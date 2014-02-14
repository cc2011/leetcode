/*
��һ����Ҫ��������ݽṹ���Ե��˽�
get������ȻӦ����O(1)�ĸ��Ӷ�ʵ�֣���ôֻ����unordered_map
���� ����map��������list�ĵ�����������
get����Ҫ���������ǣ���map�����key������Ҳ����ͷ���-1��
����ҵ��ˣ��Ͱѵ�ǰ���ʵĽڵ�ŵ�list��ǰ�棬���ص�ǰֵ
set������Ҫ����ɾ�������룬������Ҫһ��������stl�е�Ȼ��list��
set����Ҫ���������ǣ�
*/
struct CacheNode{
    int key;
    int value;
    CacheNode(int k, int v): key(k), value(v) {}
};

class LRUCache{
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){ //cacheMap[key] == 0
            return -1;
        }
		//������map���ҵ���key: 1.�ѽڵ�ŵ�����ͷ, 2.����map�еļ�¼, 3.����value
        else { 
			//��cacheList��cacheMap[key]λ�õĵ���뵽cacheList.begin()
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); 
            cacheMap[key] = cacheList.begin();//����map�еļ�¼
            return cacheList.front().value; //����value
        }
    }
    
    void set(int key, int value) {
		//û���ҵ��ڵ�: 1.����ڵ㲢����list��map, 2.Ҫ����Ƿ�����
        if(cacheMap.find(key) == cacheMap.end()) {    
            if(cacheList.size() == capacity){ //����, ɾ��ĩβ�Ľڵ�
                cacheMap.erase(cacheList.back().key); //mapҪ�ȵ���
                cacheList.pop_back();   
            }
            //�½ڵ�嵽ͷ��, ����map
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin(); //���½ڵ�λ��
        }
        else{   //�ҵ��ڵ�Ļ�, ֻ��Ҫ�ѽڵ������ͷ��, ����map
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin(); //����map
            cacheMap[key]->value = value;   //����value
        }
    }
private:
    int capacity;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;  //map��������<key, �ڵ�λ��(������)>
};