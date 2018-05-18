#include <mbed.h>
#include <C12832.h>
#include <FXOS8700Q.h>

I2C i2c(PTE25, PTE24);
FXOS8700QAccelerometer acc(i2c, FXOS8700CQ_SLAVE_ADDR1);
FXOS8700QMagnetometer  mag(i2c, FXOS8700CQ_SLAVE_ADDR1);

Serial pc(USBTX, USBRX);

// Using Arduino pin notation
C12832 lcd(D11, D13, D12, D7, D10);

int main()
{
    motion_data_units_t acc_data;

    acc.enable();


        lcd.locate(0,0);
        lcd.rect(40, 20, 70, 30,1);
        /*void rect(int x0, int y0, int x1, int y1, int colour);

        Draw a rectangle
            x0,y0 top left corner
            x1,y1 lower right corner
            color 1 set pixel, 0 erase pixel */

    while(true) {
      acc.getAxis(acc_data);

      lcd.locate(0, 0);
      lcd.printf("ACC: X=%+1.3f Y=%+1.3f Z=%+1.3f \t",
                acc_data.x, acc_data.y, acc_data.z);

      //lcd.line(50+ acc_data.x, 25, 60 + acc_data.x, 25 ,1); Hardly adjusted the line
      lcd.line(30+acc_data.x *100, 25, 30+acc_data.x*100, 25,1);
    
      /*void line(int x0, int y0, int x1, int y1, int colour);

    Draw a 1 pixel line
        x0,y0 start point
        x1,y1 start point
        color 1 set pixel, 0 erase pixel
        */
    }



}
