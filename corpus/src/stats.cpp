#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int bestNum = 50;
int main()
{
	locale::global(locale("en_US.UTF-8"));

	wifstream inf("result-700.txt");
	wofstream ouf("stats-700.txt");

	int i,j;
	int wordcount = 0;
	int res[2000];
	memset(res,0,sizeof res);

	wstring s;
	wstring ori;
	while (1)
	{
		if (!(inf >> ori))
			break;
		inf >> s;
		wordcount++;

		for (i=1;i<=bestNum;i++)
		{
			inf >> s;
			if (s==ori)
			{
				res[i]++;
				break;
			}
			inf >> s >> s;
		}
		if (inf.get()!='\n')
			inf.ignore(1024,'\n');
	}

	double ans=0;
	for (i=1;i<=bestNum;i++)
		ans+=(double)res[i]/i;

	ouf << L"共" << wordcount << L"个未知字符" << endl;
	ouf << L"总分数：" << ans << endl;
	for (i=1;i<=bestNum;i++)
		ouf << L"第" << i << L"位候选命中" << res[i] << L"个字符" << endl;
	ouf.close();
}
