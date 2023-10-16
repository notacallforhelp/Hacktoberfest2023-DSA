#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    char message[100];
    printf("Message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message,"\n")]='\0';
    int k = strlen(message);
    for (int i = 0; i < k; i++)
    {
        int asci_num = (int) message[i];
        int exp = 128;
        int counter = 8;
        while (counter)
        {
            int div = asci_num / exp;
            if (div == 0)
            {
                print_bulb(0);
            }
            else
            {
                print_bulb(1);
                asci_num = asci_num - exp;
            }
            if (asci_num != 0)
            {
                exp = exp / 2;
            }
            counter--;
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
