#include <linux/err.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/delay.h>

#include <linux/spi/spi.h>

int slic_le89156_reset(void)
{
	int gpio_reset = 20;       // GPIO for SLIC Reset

	pr_info("%s: %d\n", __func__, gpio_reset);

	gpio_free(gpio_reset);

	if (gpio_request(gpio_reset, "TS_RST") != 0) {
            pr_err("gpio_request() failed (%d)", gpio_reset);
                return -1;
	}

	if( gpio_direction_output(gpio_reset, 1) != 0 )  { 
		pr_err("gpio_direction_output() failed (%d)", gpio_reset);
			return -1;
	}

	gpio_set_value(gpio_reset, 1); // Set GPIO TS_RST to OUTPUT
	msleep(5);

	gpio_set_value(gpio_reset, 0); // Set GPIO TS_RST to LOW
	msleep(10);

	gpio_set_value(gpio_reset, 1); // Set GPIO TS_RST to HIGH
	msleep(5);

	pr_info("slic reset\n");
	gpio_free(gpio_reset);

	return 0;
}

static int test_spi_probe(struct spi_device *spi)
{
	slic_le89156_reset();
	dev_err(&spi->dev, "hello spi world\n");
	spi_write(spi, "a", 1);
	return 0;
}

static int test_spi_remove(struct spi_device *spi)
{
	dev_err(&spi->dev, "byebye spi world\n");
	return 0;
}

static const struct spi_device_id test_spi_ids[] = {
	{ "test_spi",  0 },
	{}
};
MODULE_DEVICE_TABLE(spi, test_spi_ids);

static struct spi_driver test_spi_driver = {
	.driver = {
		.name	= "test_spi",
		.owner	= THIS_MODULE,
	},
	.id_table	= test_spi_ids,
	.probe	= test_spi_probe,
	.remove	= test_spi_remove,
};

// module_init(test_spi_init);
// module_exit(test_spi_cleanup);

module_spi_driver(test_spi_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Guillaume Knispel");
MODULE_DESCRIPTION("SPI test driver");
