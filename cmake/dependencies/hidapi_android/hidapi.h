/*
 * Minimal hidapi declarations for Android stub (Raphnet USB adapters are desktop-only).
 * API subset matches hidapi 0.14.0 symbols used by libultraship raphnet code.
 * Full library: https://github.com/libusb/hidapi
 */

#ifndef HIDAPI_H__
#define HIDAPI_H__

#include <stddef.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HID_API_EXPORT
#define HID_API_CALL

typedef enum {
    HID_API_BUS_UNKNOWN = 0x00,
} hid_bus_type;

struct hid_device_;
typedef struct hid_device_ hid_device;

struct hid_device_info {
    char *path;
    unsigned short vendor_id;
    unsigned short product_id;
    wchar_t *serial_number;
    unsigned short release_number;
    wchar_t *manufacturer_string;
    wchar_t *product_string;
    unsigned short usage_page;
    unsigned short usage;
    int interface_number;
    struct hid_device_info *next;
    hid_bus_type bus_type;
};

int hid_init(void);
int hid_exit(void);
struct hid_device_info *hid_enumerate(unsigned short vendor_id, unsigned short product_id);
void hid_free_enumeration(struct hid_device_info *devs);
hid_device *hid_open_path(const char *path);
void hid_close(hid_device *dev);
const wchar_t *hid_error(hid_device *dev);
int hid_send_feature_report(hid_device *dev, const unsigned char *data, size_t length);
int hid_get_feature_report(hid_device *dev, unsigned char *data, size_t length);

#ifdef __cplusplus
}
#endif

#endif /* HIDAPI_H__ */
