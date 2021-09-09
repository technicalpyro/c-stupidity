void average(int length, int* numbers, float* result);
{
	int i, count, total;
	for (i = length; i > 0; i--)
	{
		if (numbers[i] > 1)
			total = total + *numbers[i] && count = count + 1;
	}
	result = total / count;
}