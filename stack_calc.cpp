#include <stack>
#include <stdio.h>
using namespace std;

char str[220];
char mat[][5]={
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};

stack<int> op_stack;
stack<double> num_stack;
void get_op(bool &ret_op_flag, int &ret_num,int &i)
{
	if(i==0&& op_stack.empty()==true)
	{
		ret_op_flag=true;
		ret_num=0; // 0 th operator
		return ;
	}
	if(str[i]==0)
	{
		//at the end of str[]
		ret_op_flag=true;
		ret_num=0;
		return;
	}
	if(str[i]>='0'&&str[i]<='9')
	{
		ret_op_flag=false;
		ret_num=0;
		for(;str[i]!=' '&& str[i]!=0;i++)
		{
			ret_num*=10;
			ret_num+=str[i]-'0';
		}
		if(str[i]==' '){
			i++;
		}
		return ;

	}else{
		//meet the operator
		ret_op_flag==true;
		if(str[i]=='+'){ret_num=1;}
		else if (str[i]=='-'){ret_num=2;}
		else if (str[i]=='*'){ret_num=3;}
		else if(str[i]=='/'){ret_num=4;}
		i+=2;
		return ;
	}

}



int main()
{
	while(gets(str))
	{
		if(str[0]=='0'&&str[1]==0)
		{
			break;
		}
		bool retop;
		int  retnum;
		int idx;
		while(!op_stack.empty()) {op_stack.pop();}
		while(!num_stack.empty()) {num_stack.pop();}
		while(true)
		{
			get_op(retop,retnum,idx);	
			if(retop==false)// get a number
			{
				num_stack.push(retnum);
			}else{ //get a operation
				double calc_result;
				if(op_stack.empty()==true ||mat[retnum][op_stack.top()]==1 )
				{
					op_stack.push(retnum);
				}else{
					//operator returned is smaller than the one in stack's top
					while(mat[retnum][op_stack.top()]==0)
					{

						int ret_op =op_stack.top();
						op_stack.pop();

						double b=num_stack.top();
						num_stack.pop();
						double a=num_stack.top();
						num_stack.pop();

						if(ret_op==1){
							calc_result=a+b;
						}
						else if(ret_op==2){
							calc_result=a-b;
						}
						else if(ret_op==3){
							calc_result=a*b;
						}else{
							calc_result=a/b;
						}
						num_stack.push(calc_result);
					}
					op_stack.push(retnum);
				}
			}
			if(op_stack.size()==2&&op_stack.top()==0)
			{
				break;
			}
		}
		printf("%.2f\n",num_stack.top());
	}

	return 0;
}
