#include <stdio.h>
#include <string.h>

// 例4：

int main()
{
	char arr[] = "abcdef";
	// 数组里面的元素：有 a b c d e f \0 一共7个字符
	// sizeof计算所占空间大小
	printf("%d\n", sizeof(arr));       //7*1=7 这里的arr表示整个数组，这个数组一共7个元素
	// 这里sizeof计算的是数组的大小，单位是字节
	printf("%d\n", sizeof(arr + 0));   //4/8 这里计算的是数组的大小 - arr+0是首元素的地址  
	printf("%d\n", sizeof(*arr));      //1 这里的arr是首元素，*arr即是首元素，所以计算的是首元素的大小
	printf("%d\n", sizeof(arr[1]));    //1 这里的arr[1]是指第二个元素，所以计算的是第二个元素的大小
	printf("%d\n", sizeof(&arr));      //4/8 &arr虽然是数组的地址，也是4/8个字节
	printf("%d\n", sizeof(&arr + 1));   //4/8 &arr+1是跳过整个数组后的地址
	printf("%d\n", sizeof(&arr[0] + 1));//4/8 &arr[0]+1 是第二个元素的地址
	//另一种方式：
	char arr[] = "abcdef";
	// 数组里面的元素：有 a b c d e f \0 一共7个字符
	// "a"  0x61 = 6*16^1 + 1*16^0 = 97(转化为十进制)
	printf("%d\n", strlen(arr));       //6 这里的arr是首元素地址，从起始位置开始数，直到‘\0’
	printf("%d\n", strlen(arr + 0));   //6 arr+0也是从首元素开始数，直到'\0'
	//printf("%d\n", strlen(* arr));      //报错 解引用后是首元素，即'a'，相当于把"a"传给了strlen(const char* str)函数
	//“a”的ascii码是97，函数就会把97看做是地址（参数）使用，但这个地址指向的空间不是我想要的空间然后就会出错
	//printf("%d\n", strlen(arr[1]));    //和上一样，传入'b',相当于把98当成了地址，错误
	printf("%d\n", strlen(&arr));      //6 &arr取得是数组的地址，还是相当于从首元素地址处开始向后数
	// char (*p)[7] = &arr  strlen()函数的元素类型是const char*,但是&arr的类型是char(*)[7],
	// 实参和形参类型不兼容，就会出现警告
	printf("%d\n", strlen(&arr + 1));   //随机值 它跳过了已整个数组，\0后面的内容不得而知
	printf("%d\n", strlen(&arr[0] + 1));//5 &arr[0]这里指第一个元素的地址，加1是第二个元素的地址，
	// 从第二个元素的地址开始向后数至 \0
	return 0;
}

// 例5：

int main()
{
	char* p = "abcdef";
	// 这里是指把"abcdef"这个字符串的"a"的地址放到了p里面
	printf("%d\n", sizeof(p));       //4/8 p是指针变量，这里计算的是p指针的大小
	printf("%d\n", sizeof(p + 1));   //4/8 - p+1 得到的是字符"b"的地址
	printf("%d\n", sizeof(*p));      //1   *p是第一个字符"a",
	printf("%d\n", sizeof(p[0]));    //1 int arr[10]; arr[0] == *(arr+0)  p[0] == *(p+0) == "a"
	// p[]就相当于p[1]即"b",p[2]即"c"……
	printf("%d\n", sizeof(&p));      //4/8 &p就是取出p的地址，那取地址就是4/8
	printf("%d\n", sizeof(&p + 1));   //4/8 &p+1是跳过p的地址后面一个地址，还是地址，就是4/8
	printf("%d\n", sizeof(&p[0] + 1));//4/8 &arr[0]+1 是元素"b"的地址
	return 0;
}

// 例6：
int main()
{
	char* p = "abcdef";
	// 这里是指把"abcdef"这个字符串的"a"的地址放到了p里面
	printf("%d\n", strlen(p));       //6 ，p这里指首元素地址，从开头开始数，直到‘\0’
	printf("%d\n", strlen(p + 1));   //5，p+1是从第二个元素开始数长度
	//printf("%d\n", strlen(* p));      //代码错误，解引用后是首元素，即'a'，它的ascii码是97，函数就会把97看做是参数使用，然后就会错误
	//printf("%d\n", strlen(p[1]));    //和上一样，传入'b',相当于把98当成了地址，错误
	printf("%d\n", strlen(&p));      //随机值，p存的是首元素"a"的地址，它是另外开辟的一个内存空间p
	// 所以&p指的是内存空间p，里面的元素我们不得而知，不知道什么时候取到\0，比如说"a"的地址是
	// 0x12658349,那么在p开辟的内存空间分布就可能是 49 83 65 12,我们不知道啥时候能数到\0
	printf("%d\n", strlen(&p + 1));   //随机值 从p开辟的内存空间后开始数，不知道啥时候能数到\0
	printf("%d\n", strlen(&p[0] + 1));//5  p[0]是指第一个元素"a"，&p[0]取出"a"的地址再加1，就是
	// 从"b"的地址开始向后数，所以"b"后面有加它有5个元素，就是5
	return 0;
}

