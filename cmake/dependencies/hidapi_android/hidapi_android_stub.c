/*
 * Android stub: no hidraw/libusb in NDK. Raphnet native USB is unsupported on mobile;
 * return empty enumeration so SDL handles controllers.
 */

#include "hidapi.h"

static const wchar_t kHidAndroidStubError[] = L"HIDAPI not available on Android";

int hid_init(void)
{
    return 0;
}

int hid_exit(void)
{
    return 0;
}

struct hid_device_info *hid_enumerate(unsigned short vendor_id, unsigned short product_id)
{
    (void)vendor_id;
    (void)product_id;
    return NULL;
}

void hid_free_enumeration(struct hid_device_info *devs)
{
    (void)devs;
}

hid_device *hid_open_path(const char *path)
{
    (void)path;
    return NULL;
}

void hid_close(hid_device *dev)
{
    (void)dev;
}

const wchar_t *hid_error(hid_device *dev)
{
    (void)dev;
    return kHidAndroidStubError;
}

int hid_send_feature_report(hid_device *dev, const unsigned char *data, size_t length)
{
    (void)dev;
    (void)data;
    (void)length;
    return -1;
}

int hid_get_feature_report(hid_device *dev, unsigned char *data, size_t length)
{
    (void)dev;
    (void)data;
    (void)length;
    return -1;
}
