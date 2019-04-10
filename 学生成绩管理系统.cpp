#include<iostream>
#include<string>
#include<iomanip>
   using namespace std;
  
  int num;                                   //总学生人数
  
   class student {
       friend class studentMessage;
  private:
      string ID;
     string name;
     double score[5];                       //1-4代表math、English、OPP和总成绩  ，0号单元空出
     student * next;
 15 public:
 16     student();
 17     string getName(){return name;}
 18     string getID(){return ID;}
 19     double getMath(){return score[1];}
 20     double getEnglesh(){return score[2];}
 21     double getOPP(){return score[3];}
 22     double gettotol(){return score[4];}
 23     student* getNext(){return next;}
 24 
 25     static void analyse(int ,student * ); //分析成绩
 26     void display();                          //打印成绩
 27     void swap();                          //交换对象和对象->next的信息
 28 };
 29 
 30 student::student()
 31 {
 32     cout<<"请输入学生学号 : ";cin>>ID;
 33     cout<<"请输入学生姓名 : ";cin>>name;
 34     cout<<"请输入学生的数学、英语和OPP成绩 : "<<endl;
 35     int a,b,c;
 36     cin>>a;
 37     while(a<0||a>100)
 38     {
 39         cout<<"输入成绩有误，请重新输入: "<<endl;
 40         cin>>a;    
 41     }
 42     cin>>b;
 43     while(b<0||b>100)
 44     {
 45         cout<<"输入成绩有误，请重新输入: "<<endl;
 46         cin>>b;
 47     }
 48     cin>>c;
 49     while(c<0||c>100)
 50     {
 51         cout<<"输入成绩有误，请重新输入: "<<endl;
 52         cin>>c;        
 53     }
 54     score[1]=a;
 55     score[2]=b;
 56     score[3]=c;
 57     score[4]=a+b+c;
 58     next=NULL;
 59 }
 60 
 61 void student::analyse(int a,student * first)
 62 {
 63     int you=0,liang=0,zhong=0,jige=0,bujige=0;
 64     student * t=first;
 65     double average=0;                   //平均分
 66     while(t)
 67     {
 68         int b = int(t->score[a]/10);
 69         switch(b)
 70         {
 71         case 10:
 72         case 9:you++;break;
 73         case 8:liang++;break;
 74         case 7:zhong++;break;
 75         case 6:jige++;break;
 76         default:bujige++;
 77         }
 78         average+=t->score[a];
 79         t=t->next;
 80     }
 81     average=average/num;
 82     cout<<" 考生总人数 : "<<num<<"        平均分 : "<<average<<endl;
 83     cout<<"\n 优     良      中     及格    不及格  "<<endl;
 84     cout<<" "<<you<<" \t"<<liang<<" \t"<<zhong<<"\t"<<jige<<"\t"<<bujige<<endl;
 85 }
 86 
 87 void student::display()
 88 {
 89     cout<<" "<<setw(3)<<ID<<"     "<<setw(3)<<name<<"      ";
 90     for (int i=1;i<=4;i++)
 91     {
 92         cout<<setw(3)<<score[i]<<"      ";
 93     }
 94     cout<<endl; 
 95 }
 96 
 97 void student::swap()
 98 {
 99     int j;
100     string na,id;
101     double sco[5];
102     na=name;name=next->name;next->name=na;
103     id=ID;ID=next->ID;next->ID=id;
104     for(j=1;j<=4;j++)
105     {                                            
106         sco[j]=score[j];
107         score[j]=next->score[j];    
108         next->score[j]=sco[j];
109     }
110 }
111 
112 class studentMessage{
113 private:
114     student * first;
115     student * last;
116 public:
117     studentMessage();
118     student* getFirst(){return first;}
119     student* getLast(){return last;}
120     int getNum(){return num;}
121     void add();                             //向表中增加学生成绩记录
122     void search();                          //在表中查找学生成绩记录
123     void del();                             //在表中删除学生成绩记录
124     void showOne();                         //分析一门课的成绩
125     void showAll();                         //输出所有同学所有科目的成绩
126     void sort();                            //按一门课成绩或总成绩排序
127     void clear();                           //清空所有信息并退出系统
128 
129 };
130 
131 studentMessage::studentMessage()
132 {
133     first=NULL;
134     last=NULL;
135     num=0;
136 }
137 
138 void studentMessage::add() 
139 {
140     student * t =new student;
141     student *p = first;
142     while(p){
143         if(p->ID==t->ID)
144         {
145             cout<<"\n学号输入错误或该学生成绩已经存在！(如需修改，请先删除再重新录入)"<<endl;
146             return;
147         }
148         p=p->next;
149     }
150     num++;
151     if(first==NULL)
152     {
153         first=last=t;
154         
155     }
156     else
157     {    
158         last->next=t;
159         last=last->next;
160     }
161 }
162 
163 void studentMessage::search()
164 {
165     string a;
166     cout<<"\n请输入要查找的学生的学号:";cin>>a;
167     student *t = first;
168     while(t){
169         if(t->ID==a)
170             break;
171         t=t->next;
172     }
173     if(!t)
174     {
175         cout<<"\n未找到要查找学生！"<<endl;
176         return;
177     }
178     cout<<"\n查找成功！"<<endl;
179     cout << " 学号    姓名     数学     英语     OPP     总成绩" << endl;
180     t->display();        
181 }
182 
183 void studentMessage::del()    
184 {
185     string a;
186     cout<<"\n请输入要删除的学生的学号: ";cin>>a;
187     student *t = first;
188     student *p=NULL;
189     while(t){
190         if(t->ID==a)
191             break;
192         p=t;
193         t=t->next;
194     }
195     if(!t)
196     {
197         cout<<"\n未找到要删除学生！"<<endl;
198         return;
199     }
200     if(!p)
201     {
202         first=first->next;
203         cout<<"\n成功删除学生"<<a<<endl;
204         delete t;
205     }
206     else
207     {
208         p->next=t->next;
209         cout<<"成功删除学生"<<a<<endl;
210         delete t;
211     }
212     
213     num--;
214 }
215 
216 void studentMessage::showOne()
217 {
218     int a;
219     while(1)
220     {
221         cout<<"\n想要分析哪一门成绩？请输入相应序号(1:math 2:English 3:OPP):  ";cin>>a;
222         if(a!=1&&a!=2&&a!=3)
223             cout<<"\n输入序号有误，请重新输入！"<<endl;
224         else 
225             break;
226     }
227     cout<<"\n\t成绩分析如下: \n"<<endl;
228     student::analyse(a,first);
229 }
230 
231 void studentMessage::showAll()
232 {
233     cout << "---------------------成绩列表----------------------"<< endl;
234     cout << " 学号    姓名     数学     英语     OPP     总成绩" << endl;
235     student *t = first;
236     while(t){
237         t->display();
238         t=t->next;
239     }
240 }
241 
242 void studentMessage::sort()
243 {
244     int a,n=0;                  //n--排名
245     cout<<"想要按照什么成绩排序？请输入相应序号(1.数学 2.英语 3.OPP 4.总成绩): ";
246     while(1)
247     {
248         cin>>a;
249         if (a!=1&&a!=2&&a!=3&&a!=4)
250             cout<<"\n输入序号有误，请重新输入 : ";
251         else
252             break;
253     }
254     student *t=first;
255     student *p=t;
256     while(p->next)
257     {
258         t=first;
259         while(t->next)
260         {
261             if(t->next->score[a]>=t->score[a])
262             {
263                 t->swap();
264             }
265             t=t->next;
266         }
267         p=p->next;
268     }
269     t = first;
270     cout<<"\n\t 成绩表如下: "<<endl;
271     cout<<"学号    姓名    成绩    排名"<<endl;
272     while(t){
273         n++;
274         cout<<" "<<t->getID()<<"  \t"<<t->getName()<<"  \t";
275         switch(a)
276         {
277             case 1 :cout<<t->getMath()<<"  \t"<<n<<endl;break;
278             case 2 :cout<<t->getEnglesh()<<"  \t"<<n<<endl;break;
279             case 3 :cout<<t->getOPP()<<"  \t"<<n<<endl;break;
280             case 4 :cout<<t->gettotol()<<"  \t"<<n<<endl;break;
281         }
282         t=t->next;    
283     }
284 }
285 
286 void studentMessage::clear()
287 {
288     int x;
289     cout<<"确认要清空所有信息？请输入1或2 (1:确认 2:取消) : ";cin>>x;
290     if (x==2) 
291     {
292         cout<<"\n取消清空\n"<<endl;
293         return;
294     }
295     student *t = first;
296     student *p; 
297     while(t){
298         p=t;
299         t=t->next;
300         delete p;
301     }
302     cout<<"\n清空成功！\n";
303     cout<<"退出成功！\n";
304 }
305 
306 void showMenu()
307 {
308     cout << "                               \n";
309     cout << "===============================\n";
310     cout << "      学生成绩管理系统\n\n";
311     cout << "      1.显示所有学生成绩\n";
312     cout << "      2.添加信息\n";
313     cout << "      3.查询信息\n";
314     cout << "      4.删除信息\n";
315     cout << "      5.成绩排序\n";
316     cout << "      6.单科成绩分析\n";
317     cout << "      7.清空所有信息并退出系统\n";
318     cout << "      0.退出系统\n";
319     cout << "===============================\n";
320     cout << "                               \n";
321 }
322 
323 int main()
324 {
325     int h;
326     studentMessage stuM=studentMessage();
327     while(1)
328     {
329         showMenu();
330         cout << "请输入操作对应的序号 : ";
331         cin >>h;
332         cout<<endl;
333         switch(h)
334         {
335             case 1: stuM.showAll(); break;
336             case 2: stuM.add(); break;
337             case 3: stuM.search(); break;
338             case 4: stuM.del(); break;
339             case 5: stuM.sort(); break;
340             case 6: stuM.showOne(); break;
341             case 7: stuM.clear(); return 0;
342             case 0: cout<<"\n退出成功！";return 0;
343             default:cout<<"\n输入序号有误！请输入正确的序号。"<<endl;
344         }
345     }
346 }
