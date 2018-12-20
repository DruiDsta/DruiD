#include "map_game.h"

mimimap::minimap(){
	for (int i = 0, float n = h; i < 500; ++i, n+=h){
		for (int j = 0, float m = h; j < 500; ++j, m+=h){
			segment[i][j] = generation_segment(*n, *m);
		}
	}
}
MM generation_segment(float *Pn, float *Pm){
	MM result;
	result.center.first = Pn;
	result.center.second = Pm;
	result.cell.first = randCell();
	if(result.cell.first != NUB)	result.cell.second = 2;
	else result.cell.second = 0;
	return result;
}
template <typename T> void action(T *PL){
	if(dist_action(*PL, this->segment[PL->WhSegX()][PL->WhSegY()]))
	{
		if(this->pair.first==support)	del_tox(PL->privilages);

		else if(this->pair.first==danger)
			dam(*PL, this->segment[PL->WhSegX()][PL->WhSegY()]);
	}
}
string minimap::randCell(){
	string result;
	switch(rand()%N_M){
		case 1:{result = shelter;	break;}
		case 2:{result = danger;	break;}
		case 3:{result = support;	break;}
		case 4:{result = food_map;	break;}
		default: result = NUB;
	}
	return result;
}
string getCELL(int *n, int *m){
	return this->segment[n][m].cell.first;
}
void del_tox(vector<string> VPr){
	for (int i = 0; i != VPr.size(); ++i){
		if (VPr[i]=="TOXIC")	VPr.erase(&VPr[i]);
	}
}
void dam(T *PL, MM *Seg){
	PL->set_size_body(PL->get_size_body()-(distance
		(PL->get_position(), Seg->center)-
		(PL->get_size_body() + Seg->cell.second)));
//	ещё выпадает еда...
}

template <typename T> bool dist_action(T *PL, MM *M){
	if(distance(PL->get_position(), MM->center)
		<=PL->get_size()+M->cell.second)	return true;
	else return false;
}
