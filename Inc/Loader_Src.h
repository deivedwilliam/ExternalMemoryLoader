/*
 * Loader_Src.h
 *
 *  Created on: 4 de nov de 2020
 *      Author: Deived William
 */

#ifndef INC_LOADER_SRC_H_
#define INC_LOADER_SRC_H_

#include "stm32h7xx_hal.h"
#include "w25q128_qspi.h"

#if defined(__CC_ARM)
extern uint32_t Load$$QSPI$$Base;
extern uint32_t Load$$QSPI$$Length;
#elif defined(__ICCARM__)
#pragma section =".qspi"
#pragma section =".qspi_init"
#elif defined(__GNUC__)
extern uint32_t _qspi_init_base;
extern uint32_t _qspi_init_length;
#endif


#ifdef __ICCARM__                //IAR
#define KeepInCompilation __root
#elif __CC_ARM                   //MDK-ARM
#define KeepInCompilation __attribute__((used))
#else //TASKING               //TrueStudio
#define KeepInCompilation __attribute__((used))
#endif


#define StartRamAddress          0x20000000
#define EndRamAddress            0x20080000
/* End address of the QSPI memory */
#define QSPI_END_ADDR              (1 << QSPI_FLASH_SIZE)

/* Size of buffers */
#define BUFFERSIZE                 (COUNTOF(aTxBuffer) - 1)

/* Exported macro ------------------------------------------------------------*/
#define COUNTOF(__BUFFER__)        (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

int SectorErase (uint32_t EraseStartAddress ,uint32_t EraseEndAddress);

int  QSPI_WritePage(unsigned long adr, unsigned long sz, unsigned char *buf);
static int QSPI_WriteEnable(QSPI_HandleTypeDef *hqspi);
int QSPI_AutoPollingMemReady(QSPI_HandleTypeDef *hqspi);
void ResetMemory(QSPI_HandleTypeDef *hqspi);
static int QSPI_DummyCyclesCfg(QSPI_HandleTypeDef *hqspi);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
void HAL_Delay(__IO uint32_t Delay);
void SystemClock_Config(void);
int QUADSPI_MappedMode(void);

//All system initialisation
int Init (uint8_t configureMemoryMappedMode);

//QSPI operation functions
KeepInCompilation int EraseSector (unsigned long adr);
KeepInCompilation int Write(uint32_t Address, uint32_t Size, uint8_t* buffer);
KeepInCompilation uint64_t Verify (uint32_t MemoryAddr, uint32_t RAMBufferAddr, uint32_t Size, uint32_t missalignement);
uint32_t CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal);

#endif /* INC_LOADER_SRC_H_ */
