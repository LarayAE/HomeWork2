#include "linux/module.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alex L.");

/******* global data *********/

#define MAX_NUM_ARRAY   500
static int n_array = 0;
static int m_array[MAX_NUM_ARRAY] = {0};
static int sum = 0;

/******* module params declaration *******/

module_param_array(m_array, int, &n_array, 0000);
MODULE_PARM_DESC(m_array, "modul array");

int init_module(void)
{
    int i = 0;
    for(i = 0; i < n_array; i++)
    {
        sum += m_array[i];
    }

    printk(KERN_ALERT "Sum = %d\n", sum);
    printk(KERN_ALERT "Num = %d\n", n_array);

    return 0;
}

void cleanup_module(void)
{
    printk(KERN_ALERT "paramdemo exited\n");
    return;
}
