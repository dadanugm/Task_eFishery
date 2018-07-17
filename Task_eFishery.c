#include <stdio.h>
#include <stdint.h>

void task_efishery (int data, int len);
uint8_t bit_shifter (int data, int length_shift, uint8_t line);

int data_test = 0x12345678;

int main()
{
    
    task_efishery(data_test,4);

    return 0;
}

void task_efishery (int data, int len)
{
    uint8_t temp_data[len];

    temp_data[0]=bit_shifter(data,24,0x00);
    temp_data[1]=bit_shifter(data,16,0x01);
    temp_data[2]=bit_shifter(data,8,0x02);
    temp_data[3]=bit_shifter(data,0,0x03);

    printf ("%02x \r\n",temp_data[0]);
    printf ("%02x \r\n",temp_data[1]);
    printf ("%02x \r\n",temp_data[2]);
    printf ("%02x \r\n",temp_data[3]);

    
}

uint8_t bit_shifter (int data, int length_shift, uint8_t line)
{
    uint8_t temp_sft;
    int temp_data;
    
        if (line==0x00)
        {
            temp_data = (data & 0xFF000000);
            temp_data = temp_data >> length_shift;
            temp_sft = temp_data;
        }
        else if (line==0x01)
        {
            temp_data = (data & 0x00FF0000);
            temp_data = temp_data >> length_shift;
            temp_sft = temp_data;
        }
        else if (line==0x02)
        {
            temp_data = (data & 0x0000FF00);
            temp_data = temp_data >> length_shift;
            temp_sft = temp_data;
        }
        else if (line==0x03)
        {
            temp_sft = (uint8_t) data;
        }
    
    return temp_sft;
}

