
void recursive_add_num(int *num)
{
	if ((*num) > 199999)	return;

	(*num)++;

	recursive_add_num(num);
}


int main()
{
	int num;

	recursive_add_num(&num);

	return 0;
}
