#include "i2c.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
extern "C"
{
  #include <linux/i2c-dev.h>
  #include <i2c/smbus.h>
}

static int file;
static char filename[20];

bool
InitI2C(int adapter_nr) {
  snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
  file = open(filename, O_RDWR);
  if (file < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    fprintf(stderr, "Error: could not open %s\n", filename);
    return false;
  }
  return true;
}

bool
CloseI2C() {
  if (close(file) < 0) {
    fprintf(stderr, "Error: could not close %s\n", filename);
    return false;
  }
  return true;
}

bool
SetI2CAddr(uint8_t addr) {
  if (ioctl(file, I2C_SLAVE, addr) < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    fprintf(stderr, "Error: could not set slave address to %x\n", addr);
    return false;
  }
  return true;
}

bool
WriteReg(uint8_t reg, uint8_t value) {
  if (i2c_smbus_write_byte_data(file, reg, value) < 0) {
    /* fprintf(stderr, "Error: could not write to register %d\n", reg); */
    return false;
  }
  return true;
}

uint8_t
ReadReg(uint8_t reg) {
  int32_t result;
  result = i2c_smbus_read_byte_data(file, reg);
  /* if ((result = i2c_smbus_read_byte_data(file, reg)) == -1)
    fprintf(stderr, "Error: could not read from register %d\n", reg); */

  return (uint8_t)result;
}

int32_t
ReadBytesFromAddr(uint8_t reg, uint8_t* dest, uint8_t len) {
  int read;
  if ((read = i2c_smbus_read_i2c_block_data(file, reg, len, dest)) == -1) {
    /* fprintf(stderr, "Error: could not read block from register %d\n", reg); */
    return -1;
  }
  return read;
}

bool
WriteBytesToAddr(uint8_t reg, uint8_t* values, uint8_t len) {
  //if (i2c_smbus_write_block_data(file, reg, len, values) < 0) {
  if (i2c_smbus_write_i2c_block_data(file, reg, len, values) < 0) {
    /* fprintf(stderr, "Error: could not write block data to register %d\n", reg); */
    return false;
  }
  return true;
}

