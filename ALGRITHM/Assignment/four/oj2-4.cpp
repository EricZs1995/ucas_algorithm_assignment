#include <iostream>
#include <stdio.h>
#include <stdlib.h>


double s[10],e[10];
double opt[10];
double  eps = 1e-7;


int judge(double gap){
	double st = s[0];
	opt[0] = s[0];
	for (int i = 1; i < 5; ++i)
	{
		if(st+gap>e[i])return 0;
		if(st+gap<s[i]){
			st  = s[i];
		}else{
			st += gap;
		}
		opt[i] = st;
	}
	return 1;
}

int main(){
	int i,j,k,m;
	for(i=0;i<5;i++){
		scanf("%lf%lf",&s[i],&e[i]);
	}
	double max_l = e[4]-s[0];
	double l = 0, r = max_l;
	for (int i = 0; i < 250; i++) {
		double mid = (l + r) / 2;
		if (judge(mid)) {
			l = mid + eps;
		} else r = mid - eps;
	}
	for(i = 0;i<4;i++){
		printf("%.2lf ", opt[i]);
	}
	printf("%.2lf\n", opt[4]);
	return 0;
}


def good_turing(dic,dic_unseen,V_0,V_T,N):
323     bucket = {}
324     max_r = 0
325     #计算N_r
326     for tup in dic:
327         count = dic[tup]
328         if count > max_r:
329             max_r = count
330         if count not in bucket:
331             bucket[count] = 1
332         else:
333             bucket[count] += 1
334     #计算r_*
335     r_dic = np.zeros([max_r+2])
336     p_dic = np.zeros([max_r+2])
337     for r in range(1,max_r+1):
338         if r in bucket:
339             if r+1 in bucket:
340                 r_dic[r] = (r+1)*bucket[r+1]/bucket[r]
341             else:
342                 r_dic[r] = r
343             p_dic[r] = r_dic[r]/N
344         # todo 不存在的怎么办？ 
345     #计算N_0
346     p_dic[0] = bucket[1]/(N*V_0)
347     p_dict
348     p_sum = sum(p)
349     for i in range(max_r):
350         if p_dic[i]!=0:
351             p_dic[i] /=p_sum
352     return p_dic




2 
163 def stat_uni_bi(sequences):
164     unigram_dic = OrderedDict()
165     bigram_dic = OrderedDict()
166     for seq in sequences:
167         pre = '<start>'
168         for tag in seq:
169             if tag in unigram_dic:
170                 unigram_dic[tag]+=1
171             else:
172                 unigram_dic[tag]=1
173             if pre not in bigram_dic:
174                 bigram_dic[pre] = OrderedDict()
175                 bigram_dic[pre][tag] = 1
176             else:
177                 if tag not in bigram_dic[pre]:
178                     bigram_dic[pre][tag] = 1
179                 else:
180                     bigram_dic[pre][tag] += 1
181 
182 #           if pre != '<start>':
183 #               tup = (pre,tag)
184 #               if tup in bigram_dic:
185 #                   bigram_dic[tup] += 1
186 #               else:
187 #                   bigram_dic[tup] = 1
188             pre = tag
189         tup = (pre,'<end>')
190         if tup in bigram_dic:
191             bigram_dic[tup] += 1


 def stat_bi_tup(sequences):
148     bigram_dic = OrderedDict()
149     for i,(words,tags) in enumerate(sequences):
150         for j in range(len(tags)):
151             word,tag = words[j],tags[j]
152             if tag not in bigram_dic:
153                 bigram_dic[tag] = OrderedDict()
154                 bigram_dic[tag][word] = 1
155             else:
156                 if tag not in bigram_dic[tag]:
157                     bigram_dic[tag][word] = 1
158                 else:
159                     bigram_dic[tag][word] += 1
160     return bigram_dic



9 def processdata(sequences,sequences_words,sequences_tags):
120     ind_seq_split = int(len(sequences)*0.8)
121     train_data = sequences[:ind_seq_split]
122     train_seq_words = sequences_words[:ind_seq_split]
123     train_seq_tags = sequences_tags[:ind_seq_split]
124     test_data = sequences[ind_seq_split+1:]
125     test_seq_words = sequences_words[ind_seq_split+1:]
126     test_seq_tags = sequences_tags[ind_seq_split+1:]
127 
128     uni_dic, bi_tag_dic = stat_uni_bi(train_seq_tags)
129     uni_unseen_dic, bi_tag_unseen_dic = stat_uni_bi(test_seq_tags)
130     bi_tup_dic = stat_bi_tup(train_data)
131     bi_tup_unseen_dic = stat_bi_tup(test_data)
132 
133     join_tag = bi_tag_unseen_dic.keys() & bi_tag_dic.keys()
134 #   for tag in join_tag:
135 #       del bi_tag_unseen_dic[tag]
136 
137 #   good_turing(dic,dic_unseen,V_0,V_T,N):
138     bi_tag_p = {}
139     for tag in bi_tag_dic.keys():
140         bi_tag_p[tag] = good_turing(bi_tag_dic[tag],)
141 
142     join_tup = bi_tup_unseen_dic.keys() & bi_tup_dic.keys()
143     for tup in join_tup:
144         del bi_tup_unseen_dic[tup]