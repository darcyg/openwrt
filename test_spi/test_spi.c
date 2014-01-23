#include <linux/err.h>
#include <linux/errno.h>
#include <linux/module.h>
#include <linux/device.h>

#include <linux/spi/spi.h>

static int test_spi_probe(struct spi_device *spi)
{
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
