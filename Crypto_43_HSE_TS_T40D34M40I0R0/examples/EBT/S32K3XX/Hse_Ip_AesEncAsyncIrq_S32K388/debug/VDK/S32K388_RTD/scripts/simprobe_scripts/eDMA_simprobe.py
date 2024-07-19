##############################################################################
# SYNOPSYS CONFIDENTIAL - This is an unpublished, confidential, and          #
# proprietary work of Synopsys, Inc., and may be subject to patent,          #
# copyright, trade secret, and other legal or contractual protection.        #
# This work may be used only pursuant to the terms and conditions of a       #
# written license agreement with Synopsys, Inc. All other use, reproduction, #
# distribution, or disclosure of this work is strictly prohibited.           #
##############################################################################

import os
import sys
import re
import sim

core_name = ""
mem_name = "/S32K388_System/S32K388_MCU/Memories/TEST_MEM/m_memory"
mem_start_address = int(0x70000000)
dma_mem_probe_map = {}
dma_observer_map = {}
dmamux_1_ack_map = {}
dmamux_2_ack_map = {}
dmamux_1_pin_map = {
0:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_0",
1:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_0__pin",
2:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_1__pin",
3:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_2__pin",
4:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_3__pin",
5:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_4__pin",
6:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_5__pin",
7:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_6__pin",
8:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_7__pin",
9:    "/S32K388_System/S32K388_MCU/Real_time_Control/BCTU_0/p_ipd_req_fifo_out_0",
10:    "/S32K388_System/S32K388_MCU/Real_time_Control/BCTU_0/p_ipd_req_out_0",
11:    "/S32K388_System/S32K388_MCU/Real_time_Control/BCTU_0/p_ipd_req_out_1",
12:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_req_out_0",
13:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_req_out_1",
14:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_req_out_9",
15:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_req_out_10",
16:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_req_out_0",
17:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_req_out_1",
18:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_req_out_9",
19:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_req_out_10",
20:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_req_out_0",
21:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_req_out_1",
22:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_req_out_9",
23:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_req_out_10",
24:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_dma_req_out_0",
25:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_dma_req_out_0",
26:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_26",
27:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_27",
28:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_28",
29:    "/S32K388_System/S32K388_MCU/Communication/FlexCAN_0/p_irq_dma_out",
30:    "/S32K388_System/S32K388_MCU/Communication/FlexCAN_1/p_irq_dma_out",
31:    "/S32K388_System/S32K388_MCU/Communication/FlexCAN_2/p_irq_dma_out",
32:    "/S32K388_System/S32K388_MCU/Communication/FlexCAN_3/p_irq_dma_out",
33:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_req_shifter_out_0",
34:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_req_shifter_out_1",
35:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_req_timer_out_2",
36:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_req_timer_out_3",
37:    "/S32K388_System/S32K388_MCU/Communication/LPUART_8/p_DMAREQ_TX_out",
38:    "/S32K388_System/S32K388_MCU/Communication/LPUART_0/p_DMAREQ_RX_out",
39:    "/S32K388_System/S32K388_MCU/Communication/LPUART_9/p_DMAREQ_TX_out",
40:    "/S32K388_System/S32K388_MCU/Communication/LPUART_1/p_DMAREQ_RX_out",
41:    "/S32K388_System/S32K388_MCU/Communication/lpi2c_0/p_dma_rx_req",
42:    "/S32K388_System/S32K388_MCU/Communication/lpi2c_0/p_dma_tx_req",
43:    "/S32K388_System/S32K388_MCU/Communication/lpspi_0/p_dma_tx_req",
44:    "/S32K388_System/S32K388_MCU/Communication/lpspi_0/p_dma_rx_req",
45:    "/S32K388_System/S32K388_MCU/Communication/lpspi_1/p_dma_tx_req",
46:    "/S32K388_System/S32K388_MCU/Communication/lpspi_1/p_dma_rx_req",
47:    "/S32K388_System/S32K388_MCU/Communication/lpspi_2/p_dma_tx_req",
48:    "/S32K388_System/S32K388_MCU/Communication/lpspi_2/p_dma_rx_req",
49:    "/S32K388_System/S32K388_MCU/Communication/lpspi_3/p_dma_tx_req",
50:    "/S32K388_System/S32K388_MCU/Communication/lpspi_3/p_dma_rx_req",
51:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_51",
52:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_52",
53:    "/S32K388_System/S32K388_MCU/Communication/QuadSPI_0/p_rx_dma_req_out",
54:    "/S32K388_System/S32K388_MCU/Communication/QuadSPI_0/p_tx_dma_req_out",
55:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_55",
56:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_56",
57:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_57",
58:    "/S32K388_System/S32K388_MCU/Real_time_Control/ADC_0/p_dma_req_out",
59:    "/S32K388_System/S32K388_MCU/Real_time_Control/ADC_1/p_dma_req_out",
60:    "/S32K388_System/S32K388_MCU/Real_time_Control/ADC_2/p_dma_req_out",
61:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_61",
62:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_62",
63:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_in_63"

}
dmamux_1_ack_pin_map = {
0:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_0",
1:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_0__pin",
2:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_1__pin",
3:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_2__pin",
4:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_3__pin",
5:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_4__pin",
6:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_5__pin",
7:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_6__pin",
8:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_7__pin",
9:    "/S32K388_System/S32K388_MCU/Real_time_Control/BCTU_0/p_ipd_done_fifo_in_0",
10:    "/S32K388_System/S32K388_MCU/Real_time_Control/BCTU_0/p_ipd_done_in_0",
11:    "/S32K388_System/S32K388_MCU/Real_time_Control/BCTU_0/p_ipd_done_in_1",
12:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_ack_in_0",
13:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_ack_in_1",
14:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_ack_in_9",
15:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_ack_in_10",
16:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_ack_in_0",
17:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_ack_in_1",
18:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_ack_in_9",
19:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_ack_in_10",
20:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_ack_in_0",
21:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_ack_in_1",
22:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_ack_in_9",
23:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_ack_in_10",
24:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_dma_ack_in_0",
25:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_dma_ack_in_0",
26:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_26",
27:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_27",
28:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_28",
29:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_29",
30:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_30",
31:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_31",
32:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_32",
33:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_ack_timer_out_0",
34:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_ack_timer_out_1",
35:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_ack_shifter_out_2",
36:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_ack_shifter_out_3",
37:    "/S32K388_System/S32K388_MCU/Communication/LPUART_8/p_DMAACK_TX_in",
38:    "/S32K388_System/S32K388_MCU/Communication/LPUART_0/p_DMAACK_RX_in",
39:    "/S32K388_System/S32K388_MCU/Communication/LPUART_9/p_DMAACK_TX_in",
40:    "/S32K388_System/S32K388_MCU/Communication/LPUART_1/p_DMAACK_RX_in",
41:    "/S32K388_System/S32K388_MCU/Communication/lpi2c_0/p_dma_rx_ack",
42:    "/S32K388_System/S32K388_MCU/Communication/lpi2c_0/p_dma_tx_ack",
43:    "/S32K388_System/S32K388_MCU/Communication/lpspi_0/p_dma_tx_ack",
44:    "/S32K388_System/S32K388_MCU/Communication/lpspi_0/p_dma_rx_ack",
45:    "/S32K388_System/S32K388_MCU/Communication/lpspi_1/p_dma_tx_ack",
46:    "/S32K388_System/S32K388_MCU/Communication/lpspi_1/p_dma_rx_ack",
47:    "/S32K388_System/S32K388_MCU/Communication/lpspi_2/p_dma_tx_ack",
48:    "/S32K388_System/S32K388_MCU/Communication/lpspi_2/p_dma_rx_ack",
49:    "/S32K388_System/S32K388_MCU/Communication/lpspi_3/p_dma_tx_ack",
50:    "/S32K388_System/S32K388_MCU/Communication/lpspi_3/p_dma_rx_ack",
51:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_51",
52:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_52",
53:    "/S32K388_System/S32K388_MCU/Communication/QuadSPI_0/p_rx_dma_ack_in",
54:    "/S32K388_System/S32K388_MCU/Communication/QuadSPI_0/p_tx_dma_ack_in",
55:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_55",
56:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_56",
57:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_57",
58:    "/S32K388_System/S32K388_MCU/Real_time_Control/ADC_0/p_dma_ack_in",
59:    "/S32K388_System/S32K388_MCU/Real_time_Control/ADC_1/p_dma_ack_in",
60:    "/S32K388_System/S32K388_MCU/Real_time_Control/ADC_2/p_dma_ack_in",
61:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_61",
62:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_62",
63:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_63"

}

dmamux_2_pin_map = {
0:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_0",
1:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_8__pin",
2:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_9__pin",
3:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_10__pin",
4:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_11__pin",
5:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_12__pin",
6:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_13__pin",
7:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_14__pin",
8:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_req_out_15__pin",
9:    "/S32K388_System/S32K388_MCU/Real_time_Control/BCTU_0/p_ipd_req_fifo_out_1",
10:    "/S32K388_System/S32K388_MCU/Real_time_Control/BCTU_0/p_ipd_req_out_2",
11:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_req_out_16",
12:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_req_out_17",
13:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_req_out_18",
14:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_req_out_19",
15:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_req_out_16",
16:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_req_out_17",
17:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_req_out_18",
18:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_req_out_19",
19:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_req_out_16",
20:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_req_out_17",
21:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_req_out_18",
22:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_req_out_19",
23:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_dma_req_out_1",
24:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_dma_req_out_2",
25:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_dma_req_out_1",
26:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_dma_req_out_2",
27:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_27",
28:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_28",
29:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_29",
30:    "/S32K388_System/S32K388_MCU/Communication/FlexCAN_4/p_irq_dma_out",
31:    "/S32K388_System/S32K388_MCU/Communication/FlexCAN_5/p_irq_dma_out",
32:    "/S32K388_System/S32K388_MCU/Communication/FlexCAN_6/p_irq_dma_out",
33:    "/S32K388_System/S32K388_MCU/Communication/FlexCAN_7/p_irq_dma_out",
34:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_req_shifter_out_4",
35:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_req_shifter_out_5",
36:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_req_timer_out_6",
37:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_req_timer_out_7",
38:    "/S32K388_System/S32K388_MCU/Communication/LPUART_2/p_DMAREQ_TX_out",
39:    "/S32K388_System/S32K388_MCU/Communication/LPUART_10/p_DMAREQ_RX_out",
40:    "/S32K388_System/S32K388_MCU/Communication/LPUART_11/p_DMAREQ_TX_out",
41:    "/S32K388_System/S32K388_MCU/Communication/LPUART_3/p_DMAREQ_RX_out",
42:    "/S32K388_System/S32K388_MCU/Communication/LPUART_12/p_DMAREQ_TX_out",
43:    "/S32K388_System/S32K388_MCU/Communication/LPUART_4/p_DMAREQ_RX_out",
44:    "/S32K388_System/S32K388_MCU/Communication/LPUART_13/p_DMAREQ_TX_out",
45:    "/S32K388_System/S32K388_MCU/Communication/LPUART_5/p_DMAREQ_RX_out",
46:    "/S32K388_System/S32K388_MCU/Communication/LPUART_14/p_DMAREQ_TX_out",
47:    "/S32K388_System/S32K388_MCU/Communication/LPUART_6/p_DMAREQ_RX_out",
48:    "/S32K388_System/S32K388_MCU/Communication/LPUART_15/p_DMAREQ_TX_out",
49:    "/S32K388_System/S32K388_MCU/Communication/LPUART_7/p_DMAREQ_RX_out",
50:    "/S32K388_System/S32K388_MCU/Communication/lpi2c_1/p_dma_rx_req",
51:    "/S32K388_System/S32K388_MCU/Communication/lpi2c_1/p_dma_tx_req",
52:    "/S32K388_System/S32K388_MCU/Communication/lpspi_4/p_dma_tx_req",
53:    "/S32K388_System/S32K388_MCU/Communication/lpspi_4/p_dma_rx_req",
54:    "/S32K388_System/S32K388_MCU/Communication/lpspi_5/p_dma_tx_req",
55:    "/S32K388_System/S32K388_MCU/Communication/lpspi_5/p_dma_rx_req",
56:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_56",
57:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_57",
58:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_58",
59:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_59",
60:    "/S32K388_System/S32K388_MCU/Real_time_Control/LPCMP_1/p_dma_req_out",
61:    "/S32K388_System/S32K388_MCU/Real_time_Control/LPCMP_2/p_dma_req_out",
62:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_62",
63:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_in_63",

}
dmamux_2_ack_pin_map = {
0:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_0",
1:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_8__pin",
2:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_9__pin",
3:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_10__pin",
4:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_11__pin",
5:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_12__pin",
6:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_13__pin",
7:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_14__pin",
8:    "/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/p_dma_ack_in_15__pin",
9:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_9",
10:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_10",
11:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_ack_in_16",
12:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_ack_in_17",
13:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_ack_in_18",
14:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_dma_ack_in_19",
15:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_ack_in_16",
16:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_ack_in_17",
17:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_ack_in_18",
18:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_dma_ack_in_19",
19:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_ack_in_16",
20:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_ack_in_17",
21:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_ack_in_18",
22:    "/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_dma_ack_in_19",
23:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_dma_ack_in_1",
24:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_0/p_dma_ack_in_2",
25:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_dma_ack_in_1",
26:    "/S32K388_System/S32K388_MCU/Real_time_Control/LCU_1/p_dma_ack_in_2",
27:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_27",
28:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_28",
29:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_29",
30:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_30",
31:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_31",
32:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_32",
33:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_0/p_src_ack_out_33",
34:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_ack_timer_out_4",
35:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_ack_timer_out_5",
36:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_ack_shifter_out_6",
37:    "/S32K388_System/S32K388_MCU/Communication/FlexIO_0/p_dma_ack_shifter_out_7",
38:    "/S32K388_System/S32K388_MCU/Communication/LPUART_2/p_DMAACK_TX_in",
39:    "/S32K388_System/S32K388_MCU/Communication/LPUART_10/p_DMAACK_RX_in",
40:    "/S32K388_System/S32K388_MCU/Communication/LPUART_11/p_DMAACK_TX_in",
41:    "/S32K388_System/S32K388_MCU/Communication/LPUART_3/p_DMAACK_RX_in",
42:    "/S32K388_System/S32K388_MCU/Communication/LPUART_12/p_DMAACK_TX_in",
43:    "/S32K388_System/S32K388_MCU/Communication/LPUART_4/p_DMAACK_RX_in",
44:    "/S32K388_System/S32K388_MCU/Communication/LPUART_13/p_DMAACK_TX_in",
45:    "/S32K388_System/S32K388_MCU/Communication/LPUART_5/p_DMAACK_RX_in",
46:    "/S32K388_System/S32K388_MCU/Communication/LPUART_14/p_DMAACK_TX_in",
47:    "/S32K388_System/S32K388_MCU/Communication/LPUART_6/p_DMAACK_RX_in",
48:    "/S32K388_System/S32K388_MCU/Communication/LPUART_15/p_DMAACK_TX_in",
49:    "/S32K388_System/S32K388_MCU/Communication/LPUART_7/p_DMAACK_RX_in",
50:    "/S32K388_System/S32K388_MCU/Communication/lpi2c_1/p_dma_rx_ack",
51:    "/S32K388_System/S32K388_MCU/Communication/lpi2c_1/p_dma_tx_ack",
52:    "/S32K388_System/S32K388_MCU/Communication/lpspi_4/p_dma_tx_ack",
53:    "/S32K388_System/S32K388_MCU/Communication/lpspi_4/p_dma_rx_ack",
54:    "/S32K388_System/S32K388_MCU/Communication/lpspi_5/p_dma_tx_ack",
55:    "/S32K388_System/S32K388_MCU/Communication/lpspi_5/p_dma_rx_ack",
56:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_56",
57:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_57",
58:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_58",
59:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_59",
60:    "/S32K388_System/S32K388_MCU/Real_time_Control/LPCMP_1/p_dma_ack_in",
61:    "/S32K388_System/S32K388_MCU/Real_time_Control/LPCMP_2/p_dma_ack_in",
62:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_62",
63:    "/S32K388_System/S32K388_MCU/Core_Systems/DMA_MUX_1/p_src_ack_out_63",

}



dma_trgt_list = [
"/S32K388_System/S32K388_MCU/Core_Systems/SIUL2_0/SIUL2Reg/p_target_socket",
"/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_0/p_emios_target_in",
"/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_1/p_emios_target_in",
"/S32K388_System/S32K388_MCU/Real_time_Control/eMIOS_2/p_emios_target_in",
"/S32K388_System/S32K388_MCU/Communication/FlexCAN_0/p_target_socket",
"/S32K388_System/S32K388_MCU/Communication/FlexCAN_1/p_target_socket",
"/S32K388_System/S32K388_MCU/Communication/FlexCAN_2/p_target_socket",
"/S32K388_System/S32K388_MCU/Communication/FlexCAN_3/p_target_socket",
"/S32K388_System/S32K388_MCU/Communication/FlexCAN_4/p_target_socket",
"/S32K388_System/S32K388_MCU/Communication/FlexCAN_5/p_target_socket",
"/S32K388_System/S32K388_MCU/Communication/FlexCAN_6/p_target_socket",
"/S32K388_System/S32K388_MCU/Communication/FlexCAN_7/p_target_socket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_0/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_1/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_2/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_3/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_4/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_5/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_6/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_7/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_8/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_9/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_10/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_11/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_12/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_13/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_14/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/LPUART_15/p_reg_TrgtSocket",
"/S32K388_System/S32K388_MCU/Communication/lpi2c_0/p_registers",
"/S32K388_System/S32K388_MCU/Communication/lpi2c_1/p_registers",
"/S32K388_System/S32K388_MCU/Communication/lpspi_0/p_registers",
"/S32K388_System/S32K388_MCU/Communication/lpspi_1/p_registers",
"/S32K388_System/S32K388_MCU/Communication/lpspi_2/p_registers",
"/S32K388_System/S32K388_MCU/Communication/lpspi_3/p_registers",
"/S32K388_System/S32K388_MCU/Communication/lpspi_4/p_registers",
"/S32K388_System/S32K388_MCU/Communication/lpspi_5/p_registers",
"/S32K388_System/S32K388_MCU/Communication/QuadSPI_0/p_target_socket_IPS",
]

global dmamux_src_val_pin_path

def py_assert_hw_trigger_cb(observer, args):
    global mem_start_address, mem_name
    #print('#:py_assert_hw_trigger_cb#')
    #dma_num = core_probe.find_symbol_by_name("current_dma_no", 'object')
    #dma_num_probe = sim.MemoryProbe(mem_name, dma_num.size, dma_num.start_address - mem_start_address)
    #dma_num_val = dma_num_probe.get_value()
    
    dmamux_num = core_probe.find_symbol_by_name('_ZL17current_dmamux_no', 'object')
    dmamux_num_probe = sim.MemoryProbe(mem_name, 1, dmamux_num.start_address - mem_start_address)
    dmamux_num_val = dmamux_num_probe.get_value()
    #print('symbol name for dmamux_num is %s', dmamux_num.name)
    dmamux_src = core_probe.find_symbol_by_name('_ZL18current_dmamux_src', 'object')
    dmamux_src_probe = sim.MemoryProbe(mem_name, 1, dmamux_src.start_address - mem_start_address)
    dmamux_src_val = dmamux_src_probe.get_value()
    #print('symbol name for dmamux_src is %s', dmamux_src.name)
    #channel_num = core_probe.find_symbol_by_name("m_channel_no", 'object')
    #channel_num_probe = sim.MemoryProbe(mem_name, channel_num.size, channel_num.start_address - mem_start_address)
    #dma_channel = channel_num_probe.get_value()
    #print('dmamux_src_val is ', dmamux_src_val)
    if (dmamux_num_val == 1):
        dmamux_src_val_pin_path = sim.get_full_model_name(dmamux_1_pin_map[dmamux_src_val])
    elif (dmamux_num_val == 2):
        dmamux_src_val_pin_path = sim.get_full_model_name(dmamux_2_pin_map[dmamux_src_val])
    dmamux_src_val_pin = sim.BoolProbe(dmamux_src_val_pin_path)
    dmamux_src_val_pin.set_value(1)
    #print(dmamux_src_val_pin)
    
    #print('dma mux is ', dmamux_num_val)
    #print('dmamux_src_val_pin_path', dmamux_src_val_pin_path)
    
    '''
    hw_trigger_path = sim.get_full_model_name('eDMA3_'+str(dma_num_val)+'/p_dma_ipd_req_in_'+str(dma_channel))
    hw_trigger_Pin = sim.BoolProbe(hw_trigger_path)
    if 0 == hw_trigger_Pin.get_value():
        print('Asserting : ',hw_trigger_path)
        hw_trigger_Pin.set_value(1)
    ''' 

    
def py_deassert_hw_trigger_cb(observer, args):
    global mem_start_address, mem_name
    #dma_num = core_probe.find_symbol_by_name("current_dma_no", 'object')
    #dma_num_probe = sim.MemoryProbe(mem_name, dma_num.size, dma_num.start_address - mem_start_address)
    #dma_num_val = dma_num_probe.get_value()
    
    dmamux_num = core_probe.find_symbol_by_name('_ZL17current_dmamux_no', 'object') # '_ZL17current_dmamux_no'
    dmamux_num_probe = sim.MemoryProbe(mem_name, 1, dmamux_num.start_address - mem_start_address)
    dmamux_num_val = dmamux_num_probe.get_value()
    
    dmamux_src = core_probe.find_symbol_by_name('_ZL18current_dmamux_src', 'object') # '_ZL18current_dmamux_src'
    dmamux_src_probe = sim.MemoryProbe(mem_name, 1, dmamux_src.start_address - mem_start_address)
    dmamux_src_val = dmamux_src_probe.get_value()
    
    #channel_num = core_probe.find_symbol_by_name("m_channel_no", 'object')
    #channel_num_probe = sim.MemoryProbe(mem_name, channel_num.size, channel_num.start_address - mem_start_address)
    #dma_channel = channel_num_probe.get_value()
    
    if (dmamux_num_val == 1):
        dmamux_src_val_pin_path = sim.get_full_model_name(dmamux_1_pin_map[dmamux_src_val])
    elif (dmamux_num_val == 2):
        dmamux_src_val_pin_path = sim.get_full_model_name(dmamux_2_pin_map[dmamux_src_val])
    #print('dma mux is ', dmamux_num_val)
    #print('dmamux_src_val_pin_path', dmamux_src_val_pin_path)
    dmamux_src_val_pin = sim.BoolProbe(dmamux_src_val_pin_path)
    dmamux_src_val_pin.set_value(0)
    
def ack_val_change_cb(probe):
    global dmamux_1_ack_maps
    #print("ack_val_change_cb")
    req_sig_probe = sim.BoolProbe(dmamux_1_ack_map[probe])
    req_sig_probe.set_value(0)
    probe.callback_on_value_change(0x1)
    
def ack_val_change_cb_1(probe):
    #print("ack_val_change_cb_1")
    global dmamux_2_ack_maps
    req_sig_probe = sim.BoolProbe(dmamux_2_ack_map[probe])
    req_sig_probe.set_value(0)
    probe.callback_on_value_change(0x1)
    
def py_attach_observer(observer, args):
    global dma_mem_probe_map
    global dma_observer_map
    for i in range(len(dma_trgt_list)):
        probe = sim.TargetSocketProbe(dma_trgt_list[i])
        dma_mem_probe_map[probe] = i
        observer = probe.create_observer(mem_start_tx, mem_end_tx, 0x0, 'any' )
        dma_observer_map[observer] = probe
        probe.set_manipulator(observer)
        
def mem_start_tx(observer, args):
    #print("mem_start_tx")
    args.deliver_transaction = False
    

def mem_end_tx(observer, args):
    #print("mem_end_tx")
    args.response_status = 'okay'
    is_access_obj = core_probe.find_symbol_by_name('_ZL8isAccess', 'object') # '_ZL8isAccess'
    #print('symbol name for is_access_obj is %s', is_access_obj.name)
    is_access_probe = sim.MemoryProbe(mem_name, 4, is_access_obj.start_address - mem_start_address)
    is_access_probe.set_value(dma_mem_probe_map[observer.probe])

try:
    print("#---In eDMA test Py script---#")
    
    core_name = sys.argv[1]
    #print(core_name)
    core_probe = sim.CoreProbe(core_name)
    
    for i in range(63):
        probe = sim.BoolProbe(dmamux_1_ack_pin_map[i])
        probe.set_callback(ack_val_change_cb)
        probe.callback_on_value_change(0x1)
        dmamux_1_ack_map[probe] = dmamux_1_pin_map[i]
        
        probe_1 = sim.BoolProbe(dmamux_2_ack_pin_map[i])
        probe_1.set_callback(ack_val_change_cb_1)
        probe_1.callback_on_value_change(0x1)
        dmamux_2_ack_map[probe_1] = dmamux_2_pin_map[i]        
    #print(core_probe)
    func_probe1 = core_probe.find_symbol_by_name('_Z20py_assert_hw_triggerv', 'function') # '_Z20py_assert_hw_triggerv'
    #print('symbol name for py_assert_hw_trigger is %s', func_probe1.name)
    core_probe.create_begin_instruction_observer(py_assert_hw_trigger_cb, func_probe1.start_address)    

    func_probe2 = core_probe.find_symbol_by_name('_Z22py_deassert_hw_triggerv', 'function') # '_Z22py_deassert_hw_triggerv'
    #print('symbol name for py_deassert_hw_trigger is %s', func_probe2.name)
    core_probe.create_begin_instruction_observer(py_deassert_hw_trigger_cb, func_probe2.start_address)    
    
    func_probe3 = core_probe.find_symbol_by_name('_Z18py_attach_observerv', 'function') # '_Z18py_attach_observerv'
    #print('symbol name for py_attach_observer is %s', func_probe3.name)
    core_probe.create_begin_instruction_observer(py_attach_observer, func_probe3.start_address)    
    
except StandardError as detail:
        print "Error: ",detail

        sim.print_message("PY:- ERROR. eDMA test Py script.")

sim.suspend_script()   
