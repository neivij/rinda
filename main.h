/*delay*/
#define MS   1000000        //needs estimation
/*registers*/
#define RCC_REG ((uint32_t *)0x40023800)
#define GPIOA   ((uint32_t *)0x40020000)
#define GPIOB   ((uint32_t *)0x40020400)
#define EXTI    ((uint32_t *)0x40013C00)
#define SYSCFG  ((uint32_t *)0x40013800)

/*offsets*/
#define RCC_AHB1ENR     0x30
#define RCC_APB2ENR     0x44
#define GPIO_MODE       0x0
#define GPIO_ODR        0x14
#define SYSCFG_EXTICR1  0x08
#define EXTI_RTSR       0x08
#define EXTI_IMR        0x00

/*reg values for config*/
#define GPIOAEN         (1 << 0)
#define GPIOBEN         (1 << 1)

#define SYSCFG_EN       (1 << 14)
#define GPIO_PIN_0_IN   (0 << (2 * 0))
#define GPIO_PIN_0_OUT  (1 << (2 * 0))
#define GPIO_PIN_1_OUT  (1 << (2 * 1))
#define GPIO_PIN_2_OUT  (1 << (2 * 2))
#define GPIO_PIN_3_OUT  (1 << (2 * 3))
#define GPIO_PIN_4_OUT  (1 << (2 * 4))
#define GPIO_PIN_5_OUT  (1 << (2 * 5))
#define GPIO_PIN_6_OUT  (1 << (2 * 6))
#define GPIO_PIN_7_OUT  (1 << (2 * 7))

#define RT0             (1 << 0)
#define EXTI0_NOTMASKED (1 << 0)

/*values on pin*/
#define GPIO_PIN_0 1
#define GPIO_PIN_1 (1 << 1)
#define GPIO_PIN_2 (1 << 2)
#define GPIO_PIN_3 (1 << 3)
#define GPIO_PIN_4 (1 << 4)
#define GPIO_PIN_5 (1 << 5)
#define GPIO_PIN_6 (1 << 6)
#define GPIO_PIN_7 (1 << 7)

#define GPIOA_RESET_VAL 0x0C000000  //neeeded?
#define GPIOB_RESET_VAL 0x00000280  
