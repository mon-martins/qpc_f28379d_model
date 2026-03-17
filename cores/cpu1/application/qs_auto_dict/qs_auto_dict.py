import re
import os
import sys
from datetime import datetime
from typing import List, Dict, Any, Optional

from pprint import pprint


def extract_function_names(header_path, allowed_return_types=None, required_param_types=None):
    """
    Parses a C header file and extracts function names based on filters.

    Args:
        header_path (str): Path to the C header file.
        allowed_return_types (list[str], optional): List of allowed return types.
        required_param_types (list[str], optional): List of required parameter types.

    Returns:
        list[str]: List of matching function names.
    """
    with open(header_path, 'r') as file:
        content = file.read()

    pattern = re.compile(r'\b([\w\s\*\(\)]+?)\s+(\w+)\s*\(([^;{]*)\)\s*;')
    matches = pattern.findall(content)

    if not matches:
        print(f"[INFO] No function declarations found in {header_path}.")
        return []

    matching_functions = []

    for return_type, func_name, param_list in matches:
        normalized_return = ' '.join(return_type.strip().split()).replace(' *', '*')
        normalized_params = param_list.replace('\n', ' ').replace('\t', ' ').strip()

        if allowed_return_types and normalized_return not in allowed_return_types:
            continue

        if required_param_types and not all(param_type in normalized_params for param_type in required_param_types):
            continue

        matching_functions.append(func_name)

    return matching_functions

def find_header_files(directory):
    """
    Recursively finds all .h files in a directory and its subdirectories.

    Args:
        directory (str): Path to the root directory.

    Returns:
        list[str]: List of full paths to found .h files.
    """
    header_files = []
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith('.h'):
                header_files.append(os.path.join(root, file))
    return header_files

# #============================================================
# #============================================================
# #============================================================

# # -----------------------------
# # 1️⃣ Read header files
# # -----------------------------
# def read_header_files(files: List[str]) -> str:
#     """
#     Read multiple header files and return their combined content as a single string.
#     """
#     content = ""
#     for file in files:
#         with open(file, "r", encoding="utf-8") as f:
#             content += f.read() + "\n"
#     return content

# # -----------------------------
# # 2️⃣ Parse enums
# # -----------------------------
# def parse_enums(header_text: str) -> Dict[str, Dict[str, Any]]:
#     """
#     Parse enum definitions, including typedef enums, remove comments,
#     ignore assigned values, and skip enums that have any value ending with '_SIG'.
#     """
#     # Remove comments
#     header_text = re.sub(r"/\*.*?\*/", "", header_text, flags=re.DOTALL)
#     header_text = re.sub(r"//.*", "", header_text)

#     enums = {}

#     # Handles:
#     #   enum Name { ... };
#     #   typedef enum { ... } Name;
#     #   typedef enum Name { ... } Alias;
#     pattern = re.compile(
#         r"""
#         (?:typedef\s+)?              # optional typedef
#         enum
#         (?:\s+(\w+))?                # optional tag name (capture group 1)
#         \s*\{([^}]*)\}\s*            # enum body (capture group 2)
#         (\w+)?                       # optional typedef name (capture group 3)
#         \s*;
#         """,
#         re.DOTALL | re.VERBOSE,
#     )

#     for match in pattern.finditer(header_text):
#         tag_name = match.group(1)
#         body = match.group(2)
#         typedef_name = match.group(3)

#         # The actual enum name is:
#         # - typedef name if present
#         # - otherwise tag name
#         name = typedef_name or tag_name
#         if not name:
#             continue  # anonymous enum with no typedef name → ignore

#         values = []
#         skip = False

#         for v in body.split(","):
#             v = v.strip()
#             if not v:
#                 continue
#             v = v.split("=")[0].strip()  # remove assigned values
#             if v.endswith("_SIG"):
#                 skip = True
#                 break
#             values.append(v)

#         if skip or not values:
#             continue

#         enums[name] = {"values": values, "count_name": values[-1]}

#     return enums

# # -----------------------------
# # 3️⃣ Parse structs
# # -----------------------------
# def parse_struct_fields(body: str) -> Dict[str, Dict[str, Any]]:
#     """
#     Parse struct fields.
#     """
#     fields = {}
#     for line in body.split(";"):
#         line = line.strip()
#         if not line or line.endswith(":"):
#             continue
#         # Match type and field name, optionally with array
#         m = re.match(r"([\w\s\*\_]+)\s+(\w+)(\s*\[\s*(\w+)\s*\])?", line)
#         if m:
#             ftype = m.group(1).strip()
#             fname = m.group(2).strip()
#             array_size = m.group(4).strip() if m.group(4) else None
#             fields[fname] = {"type": ftype, "array_size": array_size}
#     return fields

# def parse_structs(header_text: str) -> Dict[str, Dict[str, Any]]:
#     """
#     Parse both named structs and typedef structs.
#     Returns:
#         { struct_name: { "fields": { field_name: {"type": ..., "array_size": ...} } } }
#     """
#     # Remove comments
#     header_text = re.sub(r"/\*.*?\*/", "", header_text, flags=re.DOTALL)
#     header_text = re.sub(r"//.*", "", header_text)

#     structs = {}

#     # typedef struct { ... } Name;
#     typedef_pattern = re.compile(r"typedef\s+struct\s*\{([^}]*)\}\s*(\w+)\s*;", re.DOTALL)
#     for match in typedef_pattern.finditer(header_text):
#         body, name = match.group(1), match.group(2)
#         structs[name] = {"fields": parse_struct_fields(body)}

#     # struct Name { ... };
#     struct_pattern = re.compile(r"struct\s+(\w+)\s*\{([^}]*)\};", re.DOTALL)
#     for match in struct_pattern.finditer(header_text):
#         name, body = match.group(1), match.group(2)
#         structs[name] = {"fields": parse_struct_fields(body)}

#     return structs

# # -----------------------------
# # 4️⃣ Parse global variables
# # -----------------------------
# def get_global_variables(text: str) -> Dict[str, Dict[str, str]]:
#     """
#     Extract global variable declarations from C header text.
#     Only top-level globals are returned, not struct members.
#     Pointers and arrays are detected. All C variable modifiers are removed.
#     """
#     globals_dict = {}

#     # Remove single-line and multi-line comments
#     text_no_comments = re.sub(r'//.*?$|/\*.*?\*/', '', text, flags=re.DOTALL | re.MULTILINE)

#     # Remove typedef structs to avoid parsing members
#     text_no_structs = re.sub(r'typedef\s+struct\s+.*?\}\s*\w*\s*;', '', text_no_comments, flags=re.DOTALL)

#     # Regex to match global variable declarations
#     pattern = re.compile(
#         r'^\s*([a-zA-Z_][\w\s\*]*?)\s+'    # type, may contain spaces and *
#         r'([a-zA-Z_]\w*)'                  # variable name
#         r'(?:\s*\[\s*([a-zA-Z_]\w*|\d+)\s*\])?'  # optional array size
#         r'\s*;',
#         re.MULTILINE
#     )

#     # List of C modifiers to remove
#     modifiers = ['extern', 'static', 'const', 'volatile', 'register', 'mutable']

#     matches = pattern.findall(text_no_structs)

#     for vtype, vname, array_size in matches:
#         # Remove all modifiers
#         clean_type = vtype
#         for mod in modifiers:
#             clean_type = re.sub(rf'\b{mod}\b', '', clean_type)
#         clean_type = clean_type.strip()
#         globals_dict[vname] = {
#             "type": clean_type,
#             "array_size": array_size if array_size else None
#         }

#     return globals_dict

# # -----------------------------
# # 5️⃣ Expand globals recursively
# # -----------------------------
# def expand_struct_fields(fields: Dict[str, Any], structs: Dict[str, Any], enums: Dict[str, Any]) -> Dict[str, Any]:
#     """
#     Recursively expand struct fields.
#     """
#     expanded = {}
#     for fname, finfo in fields.items():
#         ftype = finfo["type"]
#         array_size = finfo.get("array_size")
#         base_type = ftype.replace("*", "").strip()

#         expanded[fname] = {}
#         expanded[fname]["type"] = base_type
#         expanded[fname]["array_size"] = array_size

#         if base_type in structs:
#             expanded[fname]["fields"] = expand_struct_fields(structs[base_type]["fields"], structs, enums)
        
#         enum_mapped = False

#         if array_size:
#             for enum in enums:
#                 if array_size in enums[enum]["values"]:
#                     enum_mapped = True
#                     enum_name = enum
#                     break
#             if enum_mapped:
#                 enum_values = enums[enum_name]["values"].copy()
#                 enum_values.remove(array_size)
#                 expanded[fname]["enum_values"] = enum_values

#     return expanded


# def expand_global_variables(globals_dict: Dict[str, Any], structs: Dict[str, Any], enums: Dict[str, Any]) -> Dict[str, Any]:
#     """
#     Recursively expand global variables.
#     Track pointer status using 'is_pointer'.
#     """
#     expanded = {}
#     for name, info in globals_dict.items():
#         vtype = info["type"]
#         array_size = info.get("array_size")
#         is_pointer = "*" in vtype
#         base_type = vtype.replace("*", "").strip()

#         if base_type in structs:
#             expanded[name] = {
#                 "type": base_type,
#                 "array_size": array_size,
#                 "fields": expand_struct_fields(structs[base_type]["fields"], structs, enums)
#             }
#         else:
#             if array_size in enums:
#                 enum_values = enums[array_size]["values"]
#                 expanded[name] = {
#                     "type": base_type,
#                     "array_size": f"{array_size} ({len(enum_values)})",
#                     "enum_values": enum_values
#                 }
#             else:
#                 expanded[name] = {**info, "is_pointer": is_pointer}
#     return expanded

# # -----------------------------
# # 6️⃣ Filter by multiple types
# # -----------------------------
# def filter_by_types(vars_dict: Dict[str, Any], target_types: List[str]) -> Dict[str, Any]:
#     """
#     Filter globals by type, distinguishing between pointers and instances.
#     target_types can include types with '*' to filter pointers specifically.
#     """
#     filtered = {}
#     for name, info in vars_dict.items():
#         t = info.get("type", "")
#         is_ptr = info.get("is_pointer", False)
#         check_type = f"{t}*" if is_ptr else t

#         if any(check_type == tt for tt in target_types):
#             filtered[name] = info
#         elif "fields" in info:
#             nested = filter_by_types(info["fields"], target_types)
#             if nested:
#                 filtered[name] = {**info, "fields": nested}
#     return filtered


# # -----------------------------
# # 7️⃣ Main analyze function
# # -----------------------------
# def analyze_headers(header_files: List[str], filter_types: List[str] = None) -> Dict[str, Any]:
#     """
#     Parse headers and return the structure of global variables with optional type filtering.
#     """
#     text = read_header_files(header_files)
#     enums = parse_enums(text)
#     structs = parse_structs(text)
#     globals_dict = get_global_variables(text)
#     expanded = expand_global_variables(globals_dict, structs, enums)

#     if filter_types:
#         expanded = filter_by_types(expanded, filter_types)
    
#     return expanded

# def recursive_object_dictionary(class_attributes, class_name, objects_types, path):
#     if class_attributes['type'] in objects_types:
#         source_file.write(f'     void * qs_{class_name} = &inst_ao_blinky;\n')
#         source_file.write(f'    QS_OBJ_DICTIONARY(&{class_name}, "{class_name}");\n')
#         return
#     if 'fields' in class_attributes:
#         for field in class_attributes['fields']:
#             if field == 'super' and field in objects_types:
#                 if class_attributes['fields'][field]['array_size'] == None:
#                     source_file.write(f'    QS_OBJ_DICTIONARY(&{class_name}, "{class_name}");\n')
#                 else:
#                     if 'enum_values' in class_attributes['fields'][field]:
#                        for enum_name in class_attributes['fields'][field]['enum_values']:
#                     else:



if __name__ == "__main__":
    # if len(sys.argv) != 2:
    #     raise Exception("Missing parameter. Usage: python main.py \"['./dir1', './dir2']\"")

    # # Parse input path argument
    # raw_input = sys.argv[1].strip("[] ")
    # paths = [item.strip().strip("'\"") for item in raw_input.split(',')]

    paths_to_search = ['./../../qm_files/']

    # Discover header files
    header_files = []
    for path in paths_to_search:
        header_files += find_header_files(path)

    header_files = list(set(header_files))  # Remove duplicates

    output_file_base = "auto_dict"
    header_file_name = output_file_base + ".h"
    source_file_name = output_file_base + ".c"

    with open(header_file_name, "w", encoding="utf-8") as header_file, \
         open(source_file_name, "w", encoding="utf-8") as source_file:
        
        # Header file preamble
        header_file.write("/************************************************************/\n")
        header_file.write("// Automatically generated C header file\n")
        header_file.write("/************************************************************/\n\n")

        header_file.write("#ifndef AUTO_DICT_H_\n")
        header_file.write("#define AUTO_DICT_H_\n\n")

        header_file.write("void auto_dict_init_signals(void);\n")
        header_file.write("void auto_dict_init_objects(void);\n")
        header_file.write("void auto_dict_init_states(void);\n")
        header_file.write("void auto_dict_init_all(void);\n\n")

        header_file.write("#endif \n\n")

        # Source file preamble
        source_file.write("/************************************************************/\n")
        source_file.write("// Automatically generated C source file\n")
        source_file.write("/************************************************************/\n\n")
        source_file.write(f'#include "{header_file_name}"\n')

        for path in header_files:
            rel_path = os.path.relpath(path, os.path.dirname(source_file_name))
            source_file.write(f'#include "{rel_path.replace(os.sep, "/")}"\n')

        source_file.write("\n")
        source_file.write("void auto_dict_init_signals(void){\n")

        signal_list = []
        for path in header_files:
            with open(path) as f:
                content = f.read()
            matches = re.findall(r'\b[A-Za-z0-9_]+_SIG\b', content)
            for signal_name in sorted(set(matches)):
                signal_list.append(signal_name)

        for signal in sorted(set(signal_list)):
            source_file.write(f"    QS_SIG_DICTIONARY({signal}, (void *)0);\n")
        source_file.write("}\n\n")

        # source_file.write("void auto_dict_init_objects(void){\n")
        # objects_types = ['QActive', 'QTimeEvt', 'QHsm' , 'QAsm']
        # source_file.write("}\n")

        source_file.write("void auto_dict_init_states(void){\n")

        for qm_header_file in header_files:
            states_functions = extract_function_names(
                qm_header_file,
                allowed_return_types=['QState'],
                required_param_types=['QEvt const * const']
            )

            for state in states_functions:
                source_file.write(f"    QS_FUN_DICTIONARY({state});\n")

        source_file.write("}\n")

        source_file.write("void auto_dict_init_all(void){\n")
        source_file.write("    auto_dict_init_signals();\n")
        source_file.write("    auto_dict_init_states();\n")
        source_file.write("}\n")

        


    # print(
    #     extract_function_names(
    #         './code/communication/communication.h',
    #         allowed_return_types=['QState'],
    #         required_param_types=['QEvt const * const']
    #     )
    # )

    # print(
    #     get_object_from_header_file(
    #         ['./code/main_qm.h','./code/communication/communication.h','./code/io_expander/io_expander.h'],
    #         type_filters=['QActive', 'QTimeEvt', 'QHsm' , 'QAsm']
    #     )
    # )