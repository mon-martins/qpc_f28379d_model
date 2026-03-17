################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1597725969: ../F28397D_XL_LAUNCHPAD_CPU1.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/ti/sysconfig_1.24.0/sysconfig_cli.bat" --script "D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/F28397D_XL_LAUNCHPAD_CPU1.syscfg" -o "syscfg" -s "D:/ti/c2000/C2000Ware_26_00_00_00/.metadata/sdk.json" -d "F2837xD" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1597725969 ../F28397D_XL_LAUNCHPAD_CPU1.syscfg
syscfg/board.h: build-1597725969
syscfg/board.cmd.genlibs: build-1597725969
syscfg/board.opt: build-1597725969
syscfg/board.json: build-1597725969
syscfg/pinmux.csv: build-1597725969
syscfg/device.c: build-1597725969
syscfg/device.h: build-1597725969
syscfg/device_cmd.cmd: build-1597725969
syscfg/device_cmd.c: build-1597725969
syscfg/device_cmd.h: build-1597725969
syscfg/device_cmd.opt: build-1597725969
syscfg/device_cmd.cmd.genlibs: build-1597725969
syscfg/c2000ware_libraries.cmd.genlibs: build-1597725969
syscfg/c2000ware_libraries.opt: build-1597725969
syscfg/c2000ware_libraries.c: build-1597725969
syscfg/c2000ware_libraries.h: build-1597725969
syscfg/clocktree.h: build-1597725969
syscfg: build-1597725969

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2" --include_path="D:/ti/c2000/C2000Ware_26_00_00_00/driverlib/f2837xd/driverlib" --include_path="D:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/bsp_f28379d_cpu1/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/cla_user_code/include" --include_path="D:/ti/c2000/C2000Ware_26_00_00_00/libraries/math/CLAmath/c28/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/bsp_interrupts/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/application/include" --define=CPU1 --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/DEBUG/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f2837xd_codestartbranch.obj: D:/ti/c2000/C2000Ware_26_00_00_00/device_support/f2837xd/common/source/f2837xd_codestartbranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2" --include_path="D:/ti/c2000/C2000Ware_26_00_00_00/driverlib/f2837xd/driverlib" --include_path="D:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/bsp_f28379d_cpu1/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/cla_user_code/include" --include_path="D:/ti/c2000/C2000Ware_26_00_00_00/libraries/math/CLAmath/c28/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/bsp_interrupts/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/application/include" --define=CPU1 --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/DEBUG/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2" --include_path="D:/ti/c2000/C2000Ware_26_00_00_00/driverlib/f2837xd/driverlib" --include_path="D:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/bsp_f28379d_cpu1/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/cla_user_code/include" --include_path="D:/ti/c2000/C2000Ware_26_00_00_00/libraries/math/CLAmath/c28/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/bsp_interrupts/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/application/include" --define=CPU1 --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/DEBUG/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


