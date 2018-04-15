#include "DecisionTree.h"

int main(int argc, char* argv[]){
	string filename = "source.txt";
	DecisionTree dt ;
	int attr_node = 0;
	TreeNode* treeHead = nullptr;
	set<int> readLineNum;
	vector<int> readClumNum;
	int deep = 0;
	if (dt.pretreatment(filename, readLineNum, readClumNum) == 0)
	{
		dt.CreatTree(treeHead, dt.getStatTree(), dt.getInfos(), readLineNum, readClumNum, deep);
	}
	return 0;
}
/*
* @function CreatTree Ԥ������������������ݣ���������Ϣ��������Ա��
* @param: filename �ļ���
* @param: readLineNum ��ʹ����set
* @param: readClumNum ��������set
* @return int ���غ���ִ��״̬
*/
int DecisionTree::pretreatment(string filename, set<int>& readLineNum, vector<int>& readClumNum)
{
	ifstream read(filename.c_str());
	string itemline = "";
	getline(read, itemline);
	istringstream iss(itemline);
	string attr = "";
	while(iss >> attr)
	{
		attributes* s_attr = new attributes();
		s_attr->attriName = attr;
		//��ʼ��������
		statTree.push_back(s_attr);
		//��ʼ������ӳ��
		attr_clum[attr] = attriNum;
		attriNum++;
		//��ʼ������������
		readClumNum.push_back(0);
		s_attr = nullptr;
	}

	int i  = 0;
	//��Ӿ�������
	while(true)
	{
		getline(read, itemline);
		if(itemline == "" || itemline.length() <= 1)
		{
			break;
		}
		vector<string> infoline;
		istringstream stream(itemline);
		string item = "";
		while(stream >> item)
		{
			infoline.push_back(item);
		}

		infos.push_back(infoline);
		readLineNum.insert(i);
		i++;
	}
	read.close();
	return 0;
}

int DecisionTree::statister(vector<vector<string>>& infos, vector<attributes*>& statTree, 
							set<int>& readLine, vector<int>& readClumNum)
{
	//yes��������
	int deciNum = 0;
	//ͳ��ÿһ��
	set<int>::iterator iter_end = readLine.end();
	for (set<int>::iterator line_iter = readLine.begin(); line_iter != iter_end; ++line_iter)
	{
		bool decisLine = false;
		if (infos[*line_iter][attriNum - 1] == "yes")
		{
			decisLine = true;
			deciNum++; //���ã���Ϊ�����ĺ;��������ڼ���ʱ�Զ��ͼ����������
		}
		//�������δ����������Ϊ�����У�����ͳ��
		for (int i = 0; i < attriNum - 1; i++)
		{
			if (readClumNum[i] == 0)
			{
				std::string tempitem = infos[*line_iter][i];
				auto map_iter = statTree[i]->attriItem.find(tempitem);
				//û���ҵ�
				if (map_iter == (statTree[i]->attriItem).end())
				{
					//�½�
					attrItem* attritem = new attrItem();
					attritem->itemNum.push_back(1);
					decisLine ? attritem->itemNum.push_back(1) : attritem->itemNum.push_back(0);
					attritem->itemLine.insert(*line_iter);
					//����������->itemӳ��
					(statTree[i]->attriItem)[tempitem] = attritem;
					attritem = nullptr;
				}
				else
				{
					(map_iter->second)->itemNum[0]++;
					(map_iter->second)->itemLine.insert(*line_iter);
					if(decisLine)
					{
						(map_iter->second)->itemNum[1]++;
					}
				}
			}
		}
	}
	return deciNum;
}

/*
* @function CreatTree �ݹ�DFS���������������
* @param: treeHead Ϊ���ɵľ�����
* @param: statTree Ϊ״̬����������̬���£�����������DFS�����ݸ��£����Բ���ÿ���½�״̬��
* @param: infos ������Ϣ
* @param: readLine ��ǰ��infos����Ҫ����ͳ�Ƶ��������ɺ��������
* @param: deep ����������ȣ����ڴ�ӡ
* @return void
*/
void DecisionTree::CreatTree(TreeNode* treeHead, vector<attributes*>& statTree, vector<vector<string>>& infos, 
							 set<int>& readLine, vector<int>& readClumNum, int deep)
{
	//�п�ͳ�Ƶ���
	if (readLine.size() != 0)
	{
		string treeLine = "";
		for (int i = 0; i < deep; i++)
		{
			treeLine += "--";
		}
		//��������������������еݹ�
		resetStatTree(statTree, readClumNum);
		//ͳ�Ƶ�ǰreadLine�е����ݣ�����ͳ���ļ������ԡ���Щ�У�
		//������statTree�����ڹ���һ��statTree�����������ô��棩��������Ŀ����Ϣ��
		int deciNum = statister(getInfos(), statTree, readLine, readClumNum);
		int lineNum = readLine.size();
		int attr_node = compuDecisiNote(statTree, deciNum, lineNum, readClumNum);//��������Ϊ�ֲ�����
		//���б�����
		readClumNum[attr_node] = 1;
		//��������
		TreeNode* treeNote = new TreeNode();
		treeNote->m_sAttribute = statTree[attr_node]->attriName;
		treeNote->m_iDeciNum = deciNum;
		treeNote->m_iUnDecinum = lineNum - deciNum;
		if (treeHead == nullptr)
		{
			treeHead = treeNote; //����
		}
		else
		{
			treeHead->m_vChildren.push_back(treeNote); //�ӽڵ�
		}
		cout << "�ڵ�-"<< treeLine << ">" << statTree[attr_node]->attriName << " " << deciNum << " " << lineNum - deciNum << endl;
		
		//�Ӻ��ӷ�֧���еݹ�
		for(map<string, attrItem*>::iterator map_iterator = statTree[attr_node]->attriItem.begin();
			map_iterator != statTree[attr_node]->attriItem.end(); ++map_iterator)
		{
			//��ӡ��֧
			int sum = map_iterator->second->itemNum[0];
			int deci_Num = map_iterator->second->itemNum[1];
			cout << "��֧--"<< treeLine << ">" << map_iterator->first << endl;
			//�ݹ���㡢����
			if (deci_Num != 0 && sum != deci_Num )
			{
				//������Ч����
				set<int> newReadLineNum = map_iterator->second->itemLine;
				//DFS
				CreatTree(treeNote, statTree, infos, newReadLineNum, readClumNum, deep + 1);
			}
			else
			{
				//����Ҷ�ӽڵ�
				TreeNode* treeEnd = new TreeNode();
				treeEnd->m_sAttribute = statTree[attr_node]->attriName;
				treeEnd->m_iDeciNum = deci_Num;
				treeEnd->m_iUnDecinum = sum - deci_Num;
				treeNote->m_vChildren.push_back(treeEnd);
				//��ӡҶ��
				if (deci_Num == 0)
				{
					cout << "Ҷ��---"<< treeLine << ">no" << " " << sum << endl;
				}
				else
				{
					cout << "Ҷ��---"<< treeLine << ">yes" << " " << deci_Num <<endl;
				}
			}
		}
		//��ԭ�����п�����
		readClumNum[attr_node] = 0;
	}
}
/*
* @function compuDecisiNote ����C4.5
* @param: statTree Ϊ״̬����������̬���£�����������DFS�����ݸ��£����Բ���ÿ���½�״̬��
* @param: deciNum Yes��������
* @param: lineNum ����set������
* @param: readClumNum ���ڼ����set
* @return int ��Ϣ���������Ժ�
*/
int DecisionTree::compuDecisiNote(vector<attributes*>& statTree, int deciNum, int lineNum, vector<int>& readClumNum)
{
	double max_temp = 0;
	int max_attribute = 0;
	//�ܵ�yes�е���Ϣ��
	double infoD = info_D(deciNum, lineNum);
	for (int i = 0; i < attriNum - 1; i++)
	{
		if (readClumNum[i] == 0)
		{
			double splitInfo = 0.0;
			//info
			double info_temp = Info_attr(statTree[i]->attriItem, splitInfo, lineNum);
			statTree[i]->statResult.push_back(info_temp);
			//gain
			double gain_temp = infoD - info_temp;
			statTree[i]->statResult.push_back(gain_temp);
			//split_info
			statTree[i]->statResult.push_back(splitInfo);
			//gain_info
			double temp = gain_temp / splitInfo;
			statTree[i]->statResult.push_back(temp);
			//�õ����ֵ*/
			if (temp > max_temp)
			{
				max_temp = temp;
				max_attribute = i;
			}
		}
	}
	return max_attribute;
}
/*
* @function Info_attr info_D ����Ϣ��
* @param: deciNum ��Ч��Ϣ��
* @param: sum ����Ϣ��
* @return double ����Ϣ������
*/
double DecisionTree::info_D(int deciNum, int sum)
{
	double pi = (double)deciNum / (double)sum;
	double result = 0.0;
	if (pi == 1.0 || pi == 0.0)
	{
		return result;
	}
	result = pi * (log(pi) / log((double)2)) + (1 - pi)*(log(1 - pi)/log((double)2));
	return -result;
}
/*
* @function Info_attr ����Ϣ��
* @param: deciNum ��Ч��Ϣ��
* @param: sum ����Ϣ��
* @return double 
*/
double DecisionTree::Info_attr(map<string, attrItem*>& attriItem, double& splitInfo, int lineNum)
{
	double result = 0.0;
	for (map<string, attrItem*>::iterator item = attriItem.begin();
		 item != attriItem.end();
		 ++item
		)
	{
		 double pi = (double)(item->second->itemNum[0]) / (double)lineNum;
		 splitInfo += pi * (log(pi) / log((double)2));
		 double sub_attr = info_D(item->second->itemNum[1], item->second->itemNum[0]);
		 result += pi * sub_attr;
	}
	splitInfo = -splitInfo;
	return result;
}
/*
* @function resetStatTree ����״̬��
* @param: statTree ״̬��
* @param: readClumNum ��Ҫ���������set
* @return void
*/
void DecisionTree::resetStatTree(vector<attributes*>& statTree, vector<int>& readClumNum)
{
	for (int i = 0; i < readClumNum.size() - 1; i++)
	{
		if (readClumNum[i] == 0)
		{
			map<string, attrItem*>::iterator it_end = statTree[i]->attriItem.end();
			for (map<string, attrItem*>::iterator it = statTree[i]->attriItem.begin();
				it != it_end; it++)
			{
				delete it->second;
			}
			statTree[i]->attriItem.clear();
			statTree[i]->statResult.clear();
		}
	}
}