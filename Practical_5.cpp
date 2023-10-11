#include &lt;iostream&gt;
using namespace std;
class Node
{
public:
char val;
Node *left, *right;
Node()
{
this-&gt;left = NULL;
this-&gt;right = NULL;
}
Node(char val)
{
this-&gt;val = val;
this-&gt;left = NULL;
this-&gt;right = NULL;
}
};
class Stack
{
public:
Node *node;
Stack *next;
Stack(Node *node)
{
this-&gt;node = node;
next = NULL;
}
};
class ExpressionTree
{
private:
Stack *top;
public:
ExpressionTree()
{
top = NULL;
}
void push(Node *temp)
{
if (top == NULL)
top = new Stack(temp);
else
{
Stack *ntemp = new Stack(temp);
ntemp-&gt;next = top;
top = ntemp;
}
}
Node *pop()
{
Node *ptr = top-&gt;node;
top = top-&gt;next;
return ptr;
}

Node *peek()
{
return top-&gt;node;
}
void insert(char val)
{
if (isOperand(val))
{
Node *nptr = new Node(val);
push(nptr);
}
else if (isOperator(val))
{
Node *nptr = new Node(val);
nptr-&gt;left = pop();
nptr-&gt;right = pop();
push(nptr);
}
}
bool isOperand(char ch)
{
return ch &gt;= &#39;0&#39; &amp;&amp; ch &lt;= &#39;9&#39; || ch&gt;=&#39;A&#39; &amp;&amp; ch&lt;=&#39;Z&#39; || ch&gt;=&#39;a&#39; &amp;&amp; ch&lt;=&#39;z&#39;;
}
bool isOperator(char ch)
{
return ch == &#39;+&#39; || ch == &#39;-&#39; || ch == &#39;*&#39; || ch == &#39;/&#39; || ch==&#39;^&#39; || ch==&#39;%&#39;;
}
void construct(string eqn)
{
for (int i = eqn.length() - 1; i &gt;= 0; i--)
insert(eqn[i]);
}
void inOrder(Node *ptr)
{
if (ptr != NULL)
{
inOrder(ptr-&gt;left);
cout&lt;&lt;ptr-&gt;val;
inOrder(ptr-&gt;right);
}
}
}
int main()
{
string exp;
ExpressionTree et;
cout&lt;&lt;&quot;Enter expression in Prefix form: &quot;;
cin&gt;&gt;exp;
et.construct(exp);
cout&lt;&lt;&quot;In-order Traversal of Expression Tree : &quot;;
et.inOrder(et.peek());
return 0;
}
