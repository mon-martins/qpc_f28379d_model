################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
bsp/bsp_interrupts/source/%.obj: ../bsp/bsp_interrupts/source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2" --include_path="D:/ti/c2000/C2000Ware_26_00_00_00/driverlib/f2837xd/driverlib" --include_path="D:/ti/ccs1281/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/bsp_f28379d_cpu1/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/cla_user_code/include" --include_path="D:/ti/c2000/C2000Ware_26_00_00_00/libraries/math/CLAmath/c28/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/bsp/bsp_interrupts/include" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/application/include" --define=CPU1 --define=DEBUG --define=_FLASH --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="bsp/bsp_interrupts/source/$(basename $(<F)).d_raw" --include_path="D:/git/codigos/c2000_projects/QPC_Blinky_F28379D_2/DEBUG/syscfg" --obj_directory="bsp/bsp_interrupts/source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


