#pragma once
template <class T> 
T *pSkip(T *p,int a)
{
	int i;
	for(i=0;i<a;i++)
	{
		p=p->next;
	}
	return p;
}
