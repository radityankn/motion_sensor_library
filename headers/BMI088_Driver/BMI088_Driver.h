#ifndef BMI088_DRIVER_H
#define BMI088_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

//Accelerometer Register Map
#define ACC_CHIP_ID                 0x00
#define ACC_ERR_REG                 0x02
#define ACC_STATUS                  0x03
#define ACC_DATA_X_H                0x12
#define ACC_DATA_X_L                0x13
#define ACC_DATA_Y_H                0x14
#define ACC_DATA_Y_L                0x15
#define ACC_DATA_Z_H                0x16
#define ACC_DATA_Z_L                0x17
#define ACC_SENSORTIME_DATA_0       0x18
#define ACC_SENSORTIME_DATA_1       0x19
#define ACC_SENSORTIME_DATA_2       0x1A
#define ACC_INIT_STAT_1             0x1D
#define SENSOR_TEMP_H               0x22
#define SENSOR_TEMP_L               0x23
#define ACC_FIFO_LENGTH_H           0x24
#define ACC_FIFO_LENGTH_L           0x25
#define ACC_FIFO_DATA               0x26
#define ACC_CONF                    0x40
#define ACC_FIFO_DOWNS              0x41
#define ACC_FIFO_WTM_H              0x45
#define ACC_FIFO_WTM_L              0x46
#define ACC_FIFO_CONFIG_0           0x48
#define ACC_FIFO_CONFIG_1           0x49
#define INT1_IO_CONF                0x53
#define INT2_IO_CONF                0x54
#define INT1_INT2_MAP_DATA          0x58
#define ACC_SELF_TEST               0x6D
#define ACC_PWR_CONF                0x7C
#define ACC_PWR_CTRL                0x7D
#define ACC_SOFTRESET               0x7E

//Gyroscope Register Map
#define GYRO_CHIP_ID                0x00
#define GYRO_RATE_DATA_1            0x02
#define GYRO_RATE_DATA_2            0x03
#define GYRO_RATE_DATA_3            0x04
#define GYRO_RATE_DATA_4            0x05
#define GYRO_RATE_DATA_5            0x06
#define GYRO_RATE_DATA_5            0x07
#define GYRO_INT_STAT_1             0x0A
#define FIFO_STATUS                 0x0E
#define GYRO_RANGE                  0x0F
#define GYRO_BANDWITH               0x10
#define GYRO_LPM1                   0x11
#define GYRO_SOFTRESET              0x14
#define GYRO_INT_CTRL               0x15
#define INT3_INT4_IO_CONF           0x16
#define INT3_INT4_IO_MAP            0x18
#define GYRO_FIFO_WM_ENABLE         0x1E
#define GYRO_FIFO_EXT_INT_S         0x34
#define GYRO_SELF_TEST              0x3C
#define GYRO_FIFO_CONFIG_0          0x3D
#define GYRO_FIFO_CONFIG_1          0x3E
#define GYRO_FIFO_DATA              0x3F

//Accelerometer Status & Setting Bitmask
#define ACC_STATUS_DRDY             0b10000000
#define ACC_INT_STAT_1_DRDY         0b10000000
#define ACC_FIFO_EMPTY              0x8000
#define ACC_BWP_OSR4                0x08
#define ACC_BWP_OSR2                0x09
#define ACC_BWP_NORMAL              0x0A
#define ACC_ODR_12H5                0x05
#define ACC_ODR_25HZ                0x06
#define ACC_ODR_50HZ                0x07
#define ACC_ODR_100HZ               0x08
#define ACC_ODR_200HZ               0x09
#define ACC_ODR_400HZ               0x0A
#define ACC_ODR_800HZ               0x0B
#define ACC_ODR_1600HZ              0x0C
#define ACC_RANGE_3G                0x00
#define ACC_RANGE_6G                0x01
#define ACC_RANGE_12G               0x02
#define ACC_RANGE_24G               0x04
#define FIFO_CONFIG_0_MODE_STREAM   0x00
#define FIFO_CONFIG_0_MODE_FIFO     0x01
#define FIFO_CONFIG_1_ACC_ENABLE    0b01000000
#define FIFO_CONFIG_1_INT1_EN       0b00001000
#define FIFO_CONFIG_1_INT2_EN       0b00000100
#define INT1_IO_CONF_INT1_IN        0b00010000
#define INT1_IO_CONF_INT1_OUT       0b00001000
#define INT1_IO_CONF_INT1_OD        0b00000100
#define INT1_IO_CONF_INT1_LVL       0b00000010
#define INT2_IO_CONF_INT2_IN        0b00010000
#define INT2_IO_CONF_INT2_OUT       0b00001000
#define INT2_IO_CONF_INT2_OD        0b00000100
#define INT2_IO_CONF_INT2_LVL       0b00000010
#define INT1_INT2_MAP_DATA_INT2_DRDY    0b01000000
#define INT1_INT2_MAP_DATA_INT2_FWM     0b00100000
#define INT1_INT2_MAP_DATA_INT2_FFULL   0b00010000
#define INT1_INT2_MAP_DATA_INT1_DRDY    0b00000100
#define INT1_INT2_MAP_DATA_INT1_FWM     0b00000010
#define INT1_INT2_MAP_DATA_INT1_FFULL   0b00000001
#define ACC_SELF_TEST_OFF           0x00
#define ACC_SELF_TEST_POSITIVE      0x0D
#define ACC_SELF_TEST_NEGATIVE      0x09


//Gyro Status Code


typedef struct {
    int acc_cs_pin;
    int gyr_ps_pin;
    int gyr_cs_pin;
    int clk_speed;
    int *gyro_data_buffer;
    int *acc_data_buffer;

} bmi088_spi_handler_t;

typedef struct {
    int acc_cs_pin;
    int gyr_ps_pin;
    int gyr_cs_pin;
    int clk_speed;
    int *gyro_data_buffer;
    int *acc_data_buffer;

} bmi088_spi_acc_config_t;

typedef struct {
    int acc_cs_pin;
    int gyr_ps_pin;
    int gyr_cs_pin;
    int clk_speed;
    int spi_mode;

} bmi088_spi_gyro_config_t;

int bmi088_spi_init(bmi088_spi_handler_t handler);
int bmi088_spi_gyro_init(bmi088_spi_handler_t handler);
int bmi088_spi_acc_init(bmi088_spi_handler_t handler);

int bmi088_spi_set_acc_config(bmi088_spi_handler_t *handler, bmi088_spi_acc_config_t config);
int bmi088_spi_get_acc_config(bmi088_spi_handler_t *handler, bmi088_spi_acc_config_t *config);
int bmi088_spi_read_acc_data(bmi088_spi_handler_t *handler);

int bmi088_spi_set_gyro_config(bmi088_spi_handler_t *handler, bmi088_spi_gyro_config_t config);
int bmi088_spi_get_gyro_config(bmi088_spi_handler_t *handler, bmi088_spi_gyro_config_t *config);
int bmi088_spi_read_gyro_data(bmi088_spi_handler_t *handler);

int bmi088_spi_read_register(bmi088_spi_handler_t *handler, uint8_t byte_number, uint8_t data);
int bmi088_spi_write_register(bmi088_spi_handler_t *handler, uint8_t byte_number, uint8_t *data_buffer);

#ifdef __cplusplus
}
#endif

#endif //BMI088_DRIVER_H
