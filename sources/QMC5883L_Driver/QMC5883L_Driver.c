#include "QMC5883L_Driver.h"
#include "Wire.h"

int qmc5883l_init(bmi088_spi_handler_t *handler) {
    Wire.begin(*handler)
}

int qmc5883l_set_config(bmi088_spi_handler_t *handler, bmi088_spi_gyro_config_t config) {

}

int qmc5883l_get_config(bmi088_spi_handler_t *handler, bmi088_spi_gyro_config_t *config) {

}

int qmc5883l_read_data(bmi088_spi_handler_t *handler) {

}

int qmc5883l_read_register(bmi088_spi_handler_t *handler, uint8_t byte_number, uint8_t data) {

}

int qmc5883l_write_register(bmi088_spi_handler_t *handler, uint8_t byte_number, uint8_t *data_buffer) {

}

