#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define SPI_MASTER              1
#define SPI_SLAVE               0

#define SPI_MSB_FIRST           0
#define SPI_LSB_FIRST           1

#define SPI_RISING_EDGE         0
#define SPI_FALLING_EDGE        1

#define SPI_SAMPLE_LEADING_EDGE 0
#define SPI_SAMPLE_TRAILING_EDGE 1

#define SPI_CLK_DIV_4           0
#define SPI_CLK_DIV_16          1
#define SPI_CLK_DIV_64          2
#define SPI_CLK_DIV_128         3
#define SPI_CLK_DIV_2           4
#define SPI_CLK_DIV_8           5
#define SPI_CLK_DIV_32          6

#define SPI_ROLE                SPI_MASTER
#define SPI_DATA_ORDER          SPI_MSB_FIRST
#define SPI_POLARITY            SPI_RISING_EDGE
#define SPI_PHASE               SPI_SAMPLE_LEADING_EDGE
#define SPI_CLOCK_DIV           SPI_CLK_DIV_16

#endif
