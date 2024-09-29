static int value_set(const char * val, const struct kernel_param * kp)
{
    int ret, res;

    if(val == NULL) return -EINVAL;

    ret = kstrtoint(val, 10, &res);
    
    if(ret != 0 || res < 0 || res > 100) return -EINVAL;

    param_set_int(val, kp);

    printk(KERN_ALERT "new value = %d\n", *(int *)kp->arg);
    
    return 0;
}
/**************************************************************************************/


#include "linux/module.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alex L.");

/******* global data *********/

#define MAX_NUM_ARRAY   5
static int m_array[MAX_NUM_ARRAY] = {1,1,1,1,1};
static int sum = 0;

/******* module params declaration *******/

module_param_array(m_array, int, NULL, 0000);
MODULE_PARM_DESC(m_array, "modul array");

int init_module(void)
{
    int i = 0;
    for(i = 0; i < MAX_NUM_ARRAY; i++)
    {
        sum += m_array[i];
    }

    printk(KERN_ALERT "Sum = %d\n", sum);
    printk(KERN_ALERT "Num = %d\n", MAX_NUM_ARRAY);

    return 0;
}

void cleanup_module(void)
{
    printk(KERN_ALERT "paramdemo exited\n");
    return;
}

/**************************************************************************************/

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
