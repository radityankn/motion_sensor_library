#include "Arduino.h"
#include "SPI.h"
#include "SPI_Arduino.h"

int __spi_clk_speed = 1000000;
int __spi_mosi_pin = 11;
int __spi_miso_pin = 12;
int __spi_clk_pin = 13;
int __spi_data_order = MSBFIRST;
int __spi_data_mode = SPI_MODE0

SPIClass spi_object(__spi_mosi_pin, __spi_miso_pin, __spi_clk_pin);
SPISettings spi_object_settings(__spi_clk_speed, __spi_data_order, __spi_data_mode);

void arduino_spi_settings(int clock_rate, int mosi_pin, int miso_pin, int clk_pin, int data_order, int data_mode) {
    __spi_clk_speed = clock_rate;
    __spi_mosi_pin = mosi_pin;
    __spi_miso_pin = miso_pin;
    __spi_clk_pin = clk_pin;
    __spi_data_order = data_order;
    __spi_data_mode = data_mode;
}

void arduino_spi_begin() {
    spi_object.begin();
}

void arduino_spi_begin_transaction() {
    spi_object.beginTransaction(spi_object_settings);
}

void arduino_spi_end_transaction() {
    spi_object.endTransaction();
}

void arduino_spi_transfer(int &buffer, size_t byte_size) {
    spi_object.transfer(buffer, byte_size)
}

int arduino_spi_transfer(int value) {
    return spi_object.transfer(value)
}

void arduino_spi_end() {
    spi_object.end();
}

void arduino_spi_set_bit_order() {
    __spi_data_order = data_order;
}

void arduino_spi_set_data_mode() {
    __spi_data_mode = data_mode;
}
