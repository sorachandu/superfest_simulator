//超極ネコ祭を疑似的に引くことができるプログラム
//日本版にゃんこ大戦争 ver.11.5対応
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

vector <string> rare = { "ネコホッピング", "ネコ車輪", "ネコエステ", "ねこジュラ", "ねこファイター", "ねこ海賊", "ねこ泥棒", "ねこ僧侶", "ねこ占い師", "ネコシャーマン", "ネコ魔女", "ネコアーチャー", "ネコ魔剣士", "ねこガンマン", "たけうまねこ", "ブリキネコ", "ねこロッカー", "ねこ人魚", "サイキックネコ", "ねこ陰陽師", "ネコバサミ", "ネコボクサー", "ネコ探査機", "ネコマタドール", "ネコ武闘家" };
vector <string> super = { "ネコぼさつ", "ネコ番長", "ネコザイル", "ねこタツ", "オタネコ", "ネコスイマー", "ネコリンゴ", "ネコバスたぶ", "ねこ寿司", "窓辺の乙女ネコ", "ネコバーベル", "ネコスケート", "ネコトースター", "ネコサーファー", "ネコジャンパー", "ネコフェンシング", "泉のネコ女神" };
vector <string> uber = { "幼獣ガオ", "巫女姫ミタマ", "黒獣ガオウ", "黒無垢のミタマ", "幼傑ダルターニャ", "影傑ダークダルターニャ", "厄災の子キャスリィ", "禍根の魔女キャスリィ", "幼獣ガル", "黒獣ガルディアン", "踊り子イズ", "悲嘆の踊り子イズ", "ネコルガ", "アシルガ", "クビルガ", "テコルガ", "バララガ", "トゲルガ", "ノビルガ", "オイルガ", "オコルガ", "ネコアイス", "ネコマシン", "鬼にゃんま", "ネコシュバリエ", "ねこベビー", "ねこナース", "ネコクエスト", "ラスヴォース", "召喚少年サトル", "真田幸村", "前田慶次", "織田信長", "伊達政宗", "武田信玄", "上杉謙信", "今川義元", "成田甲斐", "天草四郎", "服部半蔵", "風神のウィンディ", "雷神のサンディア", "猿帝のクウ", "召し豚のクウ", "宝杖のカッパーマイン", "冥界のカリファ", "双掌星のシシル＆コマリ", "英雄令嬢メルシュ", "妖賢女リリン", "狩猟娘テルン", "地龍ソドム", "聖龍メギドラ", "龍騎士バルス", "神龍かむくら", "竜戦機ライデン", "覇龍ディオラムス", "古龍ガングリオン", "角龍グラディオス", "邪龍ヘヴィジャーク", "うらしまタロウ", "ツルの恩返し", "ももたろう", "かさじぞう", "かぐやひめ", "カチカチヤマンズ", "さるかに合戦", "きんたろう", "舌切りすずめ", "アキラ", "西園寺メカ子", "キャットマンダディ", "ホワイトラビット", "呪術師デスピエロ", "天誅ハヤブサ", "亡者探偵ヴィグラー", "マッドシューター・サキ", "白騎士キュクロプス", "天空神ゼウス", "守護神アヌビス", "美女神アフロディーテ", "太陽神アマテラス", "繁栄神ガネーシャ", "海王神ポセイドン", "時空神クロノス", "冥界神ハデス", "堕天神ルシファー", "帝国陸軍カタパルズ", "古代軍船ガレーズ", "飛空襲撃ボンバーズ", "観測兵器ガリレオ", "温泉天国テルマエ", "空中商会コロンブス", "超竜戦機デス・トロイ", "火の精霊メララ", "水の精霊ミズリィ", "風の精霊エアル", "雷の精霊ボルト", "石の精霊ゴロー", "闇の精霊ヤミィ", "氷の精霊フリズ" };
vector <string> legend = {};

//レアの抽選用, 前回選ばれたイテレータを記録しておく
int tmp = -1;

//レアリティの抽選確率, 1あたり0.1%の重みを持つ
int chance_rare = 650;
int chance_super = 250 + chance_rare;
int chance_uber = 100 + chance_super;
int chance_legend = 0 + chance_uber;

//レアリティの抽選, 小数点第一位を含む百分率を算出するため1000の剰余をとる
int generator_rare() {
	int n = rand() % 1000;
	if (n < chance_rare) return 0;		  //レアが当選
	else if (n < chance_super) return 1;  //激レアが当選
	else if (n < chance_uber) return 2;   //超激レアが当選
	else if (n < chance_legend) return 3; //伝説レアが当選
}

//キャラの抽選
string generator_unit(int rarelity) {
	int n;
	//レア
	if (rarelity == 0) {
		//レアのみ2回連続で同じキャラが当選することがない仕様の再現
		while (true) {
			n = rand() % rare.size();
			if (n != tmp) {
				tmp = n;
				break;
			}
		}
		return rare[n];
	}

	//激レア
	if (rarelity == 1) {
		n = rand() % super.size();
		return super[n];
	}

	//超激レア
	if (rarelity == 2) {
		n = rand() % uber.size();
		return uber[n];
	}

	//伝説レア
	if (rarelity == 3) {
		n = rand() % legend.size();
		return legend[n];
	}
}


int main() {
	srand((unsigned)time(NULL));

	long long cnt = 0;
	int n = -1;
	cout << "11連で超激レア確定モードにするにゃ? yesで確定モードになるにゃ" << endl;
	string mode;
	cin >> mode;

	//"yes"が入力された場合のみ, 11連で超激レア確定モードに
	bool flag_guarantee = false;
	if (mode == "yes") flag_guarantee = true;

	//"greedy"が入力された場合のみ, 任意のキャラが出るまでガチャを引き続けるモードに
	if (mode == "greedy") {
		cout << "隠しコマンドにゃ!" << endl;
		//任意のキャラの指定
		string purpose;
		cout << "欲しいキャラを言うにゃ" << endl;
		//入力したキャラ名がガチャ内に存在しない場合,再入力を求める
		while (true) {
			cin >> purpose;
			auto item_rare = find(rare.begin(), rare.end(), purpose);
			auto item_super = find(super.begin(), super.end(), purpose);
			auto item_uber = find(uber.begin(), uber.end(), purpose);
			auto item_legend = find(legend.begin(), legend.end(), purpose);

			if (item_rare == rare.end() && item_super == super.end() && item_uber == uber.end() && item_legend == legend.end()) {
				cout << "そのキャラは知らないにゃ" << endl;
				cout << "欲しいキャラをもう一度教えてにゃ" << endl;
			}
			else break;

		}
		cout << endl;
		int i = 0;
		while (true) {
			int iter_rare = generator_rare();
			string unit_now = generator_unit(iter_rare);
			cout << i + 1 << " : " << unit_now << endl;
			//11連時は1回分お得
			if ((i + 1) % 11 != 0) cnt += 150;
			//任意のキャラが出たか判定,出たなら終了
			if (unit_now == purpose) break;
			i++;
		}
	}

	else {
		cout << "何回ガチャしたいか教えてにゃ" << endl;
		cin >> n;
		cout << n << "回ガチャる!" << endl << endl;
	}

	for (int i = 0; i < n; i++) {
		//11連で超激レア確定モード,確定枠は11連目なのでネコカン消費は不要
		if (flag_guarantee && (i + 1) % 11 == 0) {
			cout << i + 1 << " : " << generator_unit(2) << " 確定枠にゃ" << endl;
		}

		else {
			cout << i + 1 << " : " << generator_unit(generator_rare()) << endl;
			//11連時は1回分お得
			if ((i + 1) % 11 != 0) cnt += 150;
		}
	}
	cout << "消費したネコカンは " << cnt << "個にゃ!" << endl;
}