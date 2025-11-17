#ifndef SPI_ARDUINO_H
#define SPI_ARDUINO_H

#ifdef __cplusplus
extern "C" {
#endif

void arduino_spi_settings();
void arduino_spi_begin();
void arduino_spi_begin_transaction();
void arduino_spi_end_transaction();
void arduino_spi_end();
void arduino_spi_set_bit_order();
void arduino_spi_set_bit_order();
void arduino_spi_set_data_mode();
void arduino_spi_transfer();

#ifdef __cplusplus
}
#endif

#endif //SPI_ARDUINO_H