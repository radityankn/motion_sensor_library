#ifndef QMC5883L_DRIVER_H
#define QMC5883L_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#define QMC5883L_ADDR     0x0D

//Register Map of QMC5883L
#define MAG_REG_CHIP_ID   0x0D
#define MAG_REG_X_LOW     0x00
#define MAG_REG_X_HIGH    0x01
#define MAG_REG_Y_LOW     0x02
#define MAG_REG_Y_HIGH    0x03
#define MAG_REG_Z_LOW     0x04
#define MAG_REG_Z_HIGH    0x05
#define MAG_REG_STATUS    0x06
#define MAG_REG_TEMP_HIGH 0x07
#define MAG_REG_TEMP_LOW  0x08
#define MAG_REG_CTRL_1    0x09
#define MAG_REG_CTRL_2    0x0A
#define MAG_REG_SETRESET  0x0B

//Write configuration bitmask for MAG_REG_CTRL_1 dan MAG_REG_CTRL_2
#define OSR_BITMASK_512           0b00000000
#define OSR_BITMASK_256           0b01000000
#define OSR_BITMASK_128           0b10000000
#define OSR_BITMASK_64            0b11000000
#define RNG_BITMASK_2G            0b00000000
#define RNG_BITMASK_8G            0b00010000
#define ODR_BITMASK_10HZ          0b00000000
#define ODR_BITMASK_50HZ          0b00000100
#define ODR_BITMASK_100HZ         0b00001000
#define ODR_BITMASK_200HZ         0b00001100
#define MODE_BITMASK_STANDBY      0b00000000
#define MODE_BITMASK_CONTINUOUS   0b00000001
#define SOFT_RST_BITMASK          0b10000000
#define ROL_PNT_BITMASK           0b01000000

typedef struct {
    int acc_cs_pin;
    int gyr_ps_pin;
    int gyr_cs_pin;
    int clk_speed;
    int *gyro_data_buffer;
    int *acc_data_buffer;

} qmc5883l_handler_t;

typedef struct {
    int acc_cs_pin;
    int gyr_ps_pin;
    int gyr_cs_pin;
    int clk_speed;
    int spi_mode;

} qmc5883l_config_t;

int qmc5883l_init(qmc5883l_handler_t handler);
int qmc5883l_reset(qmc5883l_handler_t handler);

int qmc5883l_set_config(qmc5883l_handler_t *handler, qmc5883l_gyro_config_t config);
int qmc5883l_get_config(qmc5883l_handler_t *handler, qmc5883l_gyro_config_t *config);
int qmc5883l_read_data(qmc5883l_handler_t *handler);

int qmc5883l_read_register(qmc5883l_handler_t *handler, uint8_t byte_number, uint8_t data);
int qmc5883l_write_register(qmc5883l_handler_t *handler, uint8_t byte_number, uint8_t *data_buffer);


#ifdef __cplusplus
}
#endif

#endif //QMC5883L_DRIVER_H
