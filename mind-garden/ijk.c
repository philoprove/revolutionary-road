#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ret_length 3

int array[5] = { 1, 2, 3, 4, 1 };
int length = sizeof(array) / sizeof(int);
int ret[ret_length];
int ret_idx = 0;
int tmp_data;

void found_and_fill(int current_array_idx, int seleted) {
	int i, pre_idx = 0;
	if (seleted <= 0) {
		for (i = 0; i < ret_length; i++) {
			printf("%d ", ret[i]);
		}
		printf("\n");
		return;
	}
	for (; current_array_idx < length; current_array_idx++) {
		tmp_data = array[current_array_idx];
		pre_idx = ret_idx - 1;
		// 注意这里和python版本的不同！我是掉坑里了,没注意比较对象，写出了如下表达：
		// (ret_idx > 0 && ret[ret_idx] < tmp_data || ret_idx == 0)
		// 另外 一开始看错了， 以为Ai Aj Ak 符合 Ai<Aj<Ak的顺序，布尔表达式如下：
		//(tmp_data > ret[pre_idx] || ret_idx == 0)
		if ((pre_idx == 1 && tmp_data < ret[pre_idx])
				|| ((pre_idx != 1 && tmp_data > ret[pre_idx]) || ret_idx == 0)) {
			ret[ret_idx] = array[current_array_idx];
			ret_idx++;
			found_and_fill(current_array_idx + 1, seleted - 1);
			ret_idx--;
		}
	}
}

int main() {
	int i;
	for (i = 0; i < ret_length; i++) {
		ret[i] = 0;
	}
	found_and_fill(0, ret_length);
}
