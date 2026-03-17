/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "board.h"

//*****************************************************************************
//
// Board Configurations
// Initializes the rest of the modules.
// Call this function in your application if you wish to do all module
// initialization.
// If you wish to not use some of the initializations, instead of the
// Board_init use the individual Module_inits
//
//*****************************************************************************
void Board_init()
{
	EALLOW;

	PinMux_init();
	SYSCTL_init();
	CLA_init();
	MEMCFG_init();
	GPIO_init();
	INTERRUPT_init();

	EDIS;
}

//*****************************************************************************
//
// PINMUX Configurations
//
//*****************************************************************************
void PinMux_init()
{
	//
	// PinMux for modules assigned to CPU1
	//

	// GPIO31 -> GPIO_LED1 Pinmux
	GPIO_setPinConfig(GPIO_31_GPIO31);
	// GPIO34 -> GPIO_LED2 Pinmux
	GPIO_setPinConfig(GPIO_34_GPIO34);

}

//*****************************************************************************
//
// CLA Configurations
//
//*****************************************************************************

void myCLA0_init(){
	//
    // Configure all CLA task vectors
    // On Type-1 and Type-2 CLAs the MVECT registers accept full 16-bit task addresses as
    // opposed to offsets used on older Type-0 CLAs
    //
#pragma diag_suppress=770
    //
    // CLA Task 1
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_1, (uint16_t)&Cla1Task1);
    CLA_setTriggerSource(CLA_TASK_1, CLA_TRIGGER_SOFTWARE);
    //
    // CLA Task 2
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_2, (uint16_t)&Cla1Task2);
    CLA_setTriggerSource(CLA_TASK_2, CLA_TRIGGER_SOFTWARE);
    //
    // CLA Task 3
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_3, (uint16_t)&Cla1Task3);
    CLA_setTriggerSource(CLA_TASK_3, CLA_TRIGGER_SOFTWARE);
    //
    // CLA Task 4
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_4, (uint16_t)&Cla1Task4);
    CLA_setTriggerSource(CLA_TASK_4, CLA_TRIGGER_SOFTWARE);
    //
    // CLA Task 5
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_5, (uint16_t)&Cla1Task5);
    CLA_setTriggerSource(CLA_TASK_5, CLA_TRIGGER_SOFTWARE);
    //
    // CLA Task 6
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_6, (uint16_t)&Cla1Task6);
    CLA_setTriggerSource(CLA_TASK_6, CLA_TRIGGER_SOFTWARE);
    //
    // CLA Task 7
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_7, (uint16_t)&Cla1Task7);
    CLA_setTriggerSource(CLA_TASK_7, CLA_TRIGGER_SOFTWARE);
    //
    // CLA Task 8
    //
    CLA_mapTaskVector(myCLA0_BASE, CLA_MVECT_8, (uint16_t)&Cla1Task8);
    CLA_setTriggerSource(CLA_TASK_8, CLA_TRIGGER_SOFTWARE);
#pragma diag_warning=770
	//
    // Enable the IACK instruction to start a task on CLA in software
    // for all  8 CLA tasks. Also, globally enable all 8 tasks (or a
    // subset of tasks) by writing to their respective bits in the
    // MIER register
    //
	CLA_enableIACK(myCLA0_BASE);
    CLA_enableTasks(myCLA0_BASE, CLA_TASKFLAG_ALL);
}


void CLA_init()
{
#ifdef _FLASH
#ifndef CMDTOOL // Linker command tool is not used

    extern uint32_t Cla1funcsRunStart, Cla1funcsLoadStart, Cla1funcsLoadSize;
    extern uint32_t Cla1ConstRunStart, Cla1ConstLoadStart, Cla1ConstLoadSize;

    //
    // Copy the program and constants from FLASH to RAM before configuring
    // the CLA
    //
    memcpy((uint32_t *)&Cla1funcsRunStart, (uint32_t *)&Cla1funcsLoadStart,
           (uint32_t)&Cla1funcsLoadSize);
    memcpy((uint32_t *)&Cla1ConstRunStart, (uint32_t *)&Cla1ConstLoadStart,
        (uint32_t)&Cla1ConstLoadSize );


#endif //CMDTOOL
#endif //_FLASH

	myCLA0_init();
}

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
void GPIO_init(){
	GPIO_LED1_init();
	GPIO_LED2_init();
}

void GPIO_LED1_init(){
	GPIO_writePin(GPIO_LED1, 1);
	GPIO_setPadConfig(GPIO_LED1, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(GPIO_LED1, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(GPIO_LED1, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(GPIO_LED1, GPIO_CORE_CPU1);
}
void GPIO_LED2_init(){
	GPIO_writePin(GPIO_LED2, 0);
	GPIO_setPadConfig(GPIO_LED2, GPIO_PIN_TYPE_STD);
	GPIO_setQualificationMode(GPIO_LED2, GPIO_QUAL_SYNC);
	GPIO_setDirectionMode(GPIO_LED2, GPIO_DIR_MODE_OUT);
	GPIO_setControllerCore(GPIO_LED2, GPIO_CORE_CPU1);
}

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************
void INTERRUPT_init(){
	
	// Interrupt Settings for INT_myCLA01
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCLA01, &cla1Isr1);
	Interrupt_enable(INT_myCLA01);
	
	// Interrupt Settings for INT_myCLA02
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCLA02, &cla1Isr2);
	Interrupt_enable(INT_myCLA02);
	
	// Interrupt Settings for INT_myCLA03
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCLA03, &cla1Isr3);
	Interrupt_enable(INT_myCLA03);
	
	// Interrupt Settings for INT_myCLA04
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCLA04, &cla1Isr4);
	Interrupt_enable(INT_myCLA04);
	
	// Interrupt Settings for INT_myCLA05
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCLA05, &cla1Isr5);
	Interrupt_enable(INT_myCLA05);
	
	// Interrupt Settings for INT_myCLA06
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCLA06, &cla1Isr6);
	Interrupt_enable(INT_myCLA06);
	
	// Interrupt Settings for INT_myCLA07
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCLA07, &cla1Isr7);
	Interrupt_enable(INT_myCLA07);
	
	// Interrupt Settings for INT_myCLA08
	// ISR need to be defined for the registered interrupts
	Interrupt_register(INT_myCLA08, &cla1Isr8);
	Interrupt_enable(INT_myCLA08);
}
//*****************************************************************************
//
// MEMCFG Configurations
//
//*****************************************************************************
void MEMCFG_init(){
	//
	// Initialize RAMs
	//
	MemCfg_initSections(MEMCFG_SECT_MSGCPUTOCPU);
	MemCfg_initSections(MEMCFG_SECT_MSGCPUTOCLA1);
	MemCfg_initSections(MEMCFG_SECT_MSGCLA1TOCPU);
	while(!MemCfg_getInitStatus(MEMCFG_SECT_MSGCPUTOCPU));
	while(!MemCfg_getInitStatus(MEMCFG_SECT_MSGCPUTOCLA1));
	while(!MemCfg_getInitStatus(MEMCFG_SECT_MSGCLA1TOCPU));
	//
	// Configure LSRAMs
	//
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS0, MEMCFG_LSRAMCONTROLLER_CPU_ONLY);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS1, MEMCFG_LSRAMCONTROLLER_CPU_ONLY);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS2, MEMCFG_LSRAMCONTROLLER_CPU_ONLY);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS3, MEMCFG_LSRAMCONTROLLER_CPU_CLA1);
	MemCfg_setCLAMemType(MEMCFG_SECT_LS3, MEMCFG_CLA_MEM_DATA);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS4, MEMCFG_LSRAMCONTROLLER_CPU_CLA1);
	MemCfg_setCLAMemType(MEMCFG_SECT_LS4, MEMCFG_CLA_MEM_PROGRAM);
	MemCfg_setLSRAMControllerSel(MEMCFG_SECT_LS5, MEMCFG_LSRAMCONTROLLER_CPU_CLA1);
	MemCfg_setCLAMemType(MEMCFG_SECT_LS5, MEMCFG_CLA_MEM_PROGRAM);
	//
	// Configure GSRAMs
	//
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS0, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS1, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS2, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS3, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS4, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS5, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS6, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS7, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS8, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS9, MEMCFG_GSRAMCONTROLLER_CPU1);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS10, MEMCFG_GSRAMCONTROLLER_CPU2);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS11, MEMCFG_GSRAMCONTROLLER_CPU2);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS12, MEMCFG_GSRAMCONTROLLER_CPU2);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS13, MEMCFG_GSRAMCONTROLLER_CPU2);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS14, MEMCFG_GSRAMCONTROLLER_CPU2);
	MemCfg_setGSRAMControllerSel(MEMCFG_SECT_GS15, MEMCFG_GSRAMCONTROLLER_CPU2);
	//
	// ROM Access Configuration
	//
	MemCfg_enableROMWaitState();
	MemCfg_disableROMPrefetch();
	//
	// Configure Access Protection for RAMs
	//
	MemCfg_setProtection(MEMCFG_SECT_D0, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_D1, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS0, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS1, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS2, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS3, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS4, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_LS5, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS0, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS1, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS2, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS3, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS4, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS5, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS6, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS7, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS8, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS9, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS10, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS11, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS12, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS13, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS14, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	MemCfg_setProtection(MEMCFG_SECT_GS15, MEMCFG_PROT_ALLOWCPUFETCH | MEMCFG_PROT_ALLOWCPUWRITE | MEMCFG_PROT_ALLOWDMAWRITE);
	//
	// Lock/Commit Registers
	//
	//
	// Enable Access Violation Interrupt
	//
	//
	// Correctable error Interrupt
	//
	MemCfg_setCorrErrorThreshold(0);
	MemCfg_disableCorrErrorInterrupt(MEMCFG_CERR_CPUREAD);
}        
//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************
void SYSCTL_init(){
	//
    // sysctl initialization
	//
    SysCtl_setStandbyQualificationPeriod(2);

    SysCtl_disableMCD();

    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 3, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 4, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 5, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 6, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 7, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 8, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 9, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 10, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 11, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL0_EPWM, 12, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL1_ECAP, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL1_ECAP, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL1_ECAP, 3, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL1_ECAP, 4, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL1_ECAP, 5, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL1_ECAP, 6, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL2_EQEP, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL2_EQEP, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL2_EQEP, 3, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL4_SD, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL4_SD, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL5_SCI, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL5_SCI, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL5_SCI, 3, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL5_SCI, 4, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL6_SPI, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL6_SPI, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL6_SPI, 3, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL7_I2C, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL7_I2C, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL8_CAN, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL8_CAN, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL9_MCBSP, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL9_MCBSP, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL11_ADC, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL11_ADC, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL11_ADC, 3, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL11_ADC, 4, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL12_CMPSS, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL12_CMPSS, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL12_CMPSS, 3, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL12_CMPSS, 4, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL12_CMPSS, 5, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL12_CMPSS, 6, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL12_CMPSS, 7, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL12_CMPSS, 8, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL14_DAC, 1, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL14_DAC, 2, SYSCTL_CPUSEL_CPU1);
    SysCtl_selectCPUForPeripheral(SYSCTL_CPUSEL14_DAC, 3, SYSCTL_CPUSEL_CPU1);

    SysCtl_selectSecController(SYSCTL_SEC_CONTROLLER_CLA, SYSCTL_SEC_CONTROLLER_CLA);

    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CLA1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DMA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER0);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TIMER2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_HRPWM);
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
    SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_GTBCLKSYNC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EMIF1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EMIF2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM4);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM5);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM6);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM7);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM8);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM9);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM10);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM11);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EPWM12);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP4);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP5);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ECAP6);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_EQEP3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SD1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SD2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCIC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SCID);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SPIA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SPIB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_SPIC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2CA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_I2CB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CANA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CANB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_MCBSPA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_MCBSPB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_USBA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_UPPA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCC);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_ADCD);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS1);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS2);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS3);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS4);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS5);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS6);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS7);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_CMPSS8);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DACA);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DACB);
    SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_DACC);

}

