#include "tusb.h"
#include "pico/stdlib.h"
#include "msc_disk.h"

#define GPIO_LINUX 28
#define GPIO_WINDOWS 29

/*------------- MAIN -------------*/
int main(void)
{

  // init device stack on configured roothub port
  tusb_init();

  gpio_init(GPIO_LINUX);
  gpio_init(GPIO_WINDOWS);
  gpio_set_dir(GPIO_LINUX, false);
  gpio_set_dir(GPIO_WINDOWS, false);
  gpio_pull_up(GPIO_LINUX);
  gpio_pull_up(GPIO_WINDOWS);


  while (1)
  {
    tud_task(); // tinyusb device task

    if ( !gpio_get(GPIO_LINUX) && !gpio_get(GPIO_WINDOWS)){
      setSwitchValue(CONFIG_DEFAULT);
    } else if ( !gpio_get(GPIO_LINUX)){
      setSwitchValue(CONFIG_LINUX);
    } else if ( !gpio_get(GPIO_WINDOWS)){
      setSwitchValue(CONFIG_WINDOWS);
    } else { //neither are pulled down, switch in the middle
      setSwitchValue(CONFIG_STOP);
    }
  }

  return 0;
}

//--------------------------------------------------------------------+
// Device callbacks
//--------------------------------------------------------------------+

// Invoked when device is mounted
void tud_mount_cb(void)
{
}

// Invoked when device is unmounted
void tud_umount_cb(void)
{
}

// Invoked when usb bus is suspended
// remote_wakeup_en : if host allow us  to perform remote wakeup
// Within 7ms, device must draw an average of current less than 2.5 mA from bus
void tud_suspend_cb(bool remote_wakeup_en)
{
  (void) remote_wakeup_en;
}

// Invoked when usb bus is resumed
void tud_resume_cb(void)
{
}
