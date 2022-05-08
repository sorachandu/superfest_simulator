//���Ƀl�R�Ղ��^���I�Ɉ������Ƃ��ł���v���O����
//���{�łɂ�񂱑�푈 ver.11.5�Ή�
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

vector <string> rare = { "�l�R�z�b�s���O", "�l�R�ԗ�", "�l�R�G�X�e", "�˂��W����", "�˂��t�@�C�^�[", "�˂��C��", "�˂��D�_", "�˂��m��", "�˂��肢�t", "�l�R�V���[�}��", "�l�R����", "�l�R�A�[�`���[", "�l�R�����m", "�˂��K���}��", "�������܂˂�", "�u���L�l�R", "�˂����b�J�[", "�˂��l��", "�T�C�L�b�N�l�R", "�˂��A�z�t", "�l�R�o�T�~", "�l�R�{�N�T�[", "�l�R�T���@", "�l�R�}�^�h�[��", "�l�R������" };
vector <string> super = { "�l�R�ڂ���", "�l�R�Ԓ�", "�l�R�U�C��", "�˂��^�c", "�I�^�l�R", "�l�R�X�C�}�[", "�l�R�����S", "�l�R�o�X����", "�˂����i", "���ӂ̉����l�R", "�l�R�o�[�x��", "�l�R�X�P�[�g", "�l�R�g�[�X�^�[", "�l�R�T�[�t�@�[", "�l�R�W�����p�[", "�l�R�t�F���V���O", "��̃l�R���_" };
vector <string> uber = { "�c�b�K�I", "�ޏ��P�~�^�}", "���b�K�I�E", "�����C�̃~�^�}", "�c���_���^�[�j��", "�e���_�[�N�_���^�[�j��", "��Ђ̎q�L���X���B", "�Ѝ��̖����L���X���B", "�c�b�K��", "���b�K���f�B�A��", "�x��q�C�Y", "�ߒQ�̗x��q�C�Y", "�l�R���K", "�A�V���K", "�N�r���K", "�e�R���K", "�o�����K", "�g�Q���K", "�m�r���K", "�I�C���K", "�I�R���K", "�l�R�A�C�X", "�l�R�}�V��", "�S�ɂ���", "�l�R�V���o���G", "�˂��x�r�[", "�˂��i�[�X", "�l�R�N�G�X�g", "���X���H�[�X", "�������N�T�g��", "�^�c�K��", "�O�c�c��", "�D�c�M��", "�ɒB���@", "���c�M��", "�㐙���M", "����`��", "���c�b��", "�V���l�Y", "��������", "���_�̃E�B���f�B", "���_�̃T���f�B�A", "����̃N�E", "�����؂̃N�E", "���̃J�b�p�[�}�C��", "���E�̃J���t�@", "�o�����̃V�V�����R�}��", "�p�Y�ߏ상���V��", "�d����������", "����e����", "�n���\�h��", "�������M�h��", "���R�m�o���X", "�_�����ނ���", "����@���C�f��", "�e���f�B�I�����X", "�×��K���O���I��", "�p���O���f�B�I�X", "�ח��w���B�W���[�N", "���炵�܃^���E", "�c���̉��Ԃ�", "�������낤", "����������", "������Ђ�", "�J�`�J�`���}���Y", "���邩�ɍ���", "���񂽂낤", "��؂肷����", "�A�L��", "���������J�q", "�L���b�g�}���_�f�B", "�z���C�g���r�b�g", "��p�t�f�X�s�G��", "�V�n�n���u�T", "�S�ҒT�ピ�B�O���[", "�}�b�h�V���[�^�[�E�T�L", "���R�m�L���N���v�X", "�V��_�[�E�X", "���_�A�k�r�X", "�����_�A�t���f�B�[�e", "���z�_�A�}�e���X", "�ɉh�_�K�l�[�V��", "�C���_�|�Z�C�h��", "����_�N���m�X", "���E�_�n�f�X", "�V�_���V�t�@�[", "�鍑���R�J�^�p���Y", "�Ñ�R�D�K���[�Y", "���P���{���o�[�Y", "�ϑ�����K�����I", "����V���e���}�G", "�󒆏���R�����u�X", "������@�f�X�E�g���C", "�΂̐��상����", "���̐���~�Y���B", "���̐���G�A��", "���̐���{���g", "�΂̐���S���[", "�ł̐��샄�~�B", "�X�̐���t���Y" };
vector <string> legend = {};

//���A�̒��I�p, �O��I�΂ꂽ�C�e���[�^���L�^���Ă���
int tmp = -1;

//���A���e�B�̒��I�m��, 1������0.1%�̏d�݂�����
int chance_rare = 650;
int chance_super = 250 + chance_rare;
int chance_uber = 100 + chance_super;
int chance_legend = 0 + chance_uber;

//���A���e�B�̒��I, �����_���ʂ��܂ޕS�������Z�o���邽��1000�̏�]���Ƃ�
int generator_rare() {
	int n = rand() % 1000;
	if (n < chance_rare) return 0;		  //���A�����I
	else if (n < chance_super) return 1;  //�����A�����I
	else if (n < chance_uber) return 2;   //�������A�����I
	else if (n < chance_legend) return 3; //�`�����A�����I
}

//�L�����̒��I
string generator_unit(int rarelity) {
	int n;
	//���A
	if (rarelity == 0) {
		//���A�̂�2��A���œ����L���������I���邱�Ƃ��Ȃ��d�l�̍Č�
		while (true) {
			n = rand() % rare.size();
			if (n != tmp) {
				tmp = n;
				break;
			}
		}
		return rare[n];
	}

	//�����A
	if (rarelity == 1) {
		n = rand() % super.size();
		return super[n];
	}

	//�������A
	if (rarelity == 2) {
		n = rand() % uber.size();
		return uber[n];
	}

	//�`�����A
	if (rarelity == 3) {
		n = rand() % legend.size();
		return legend[n];
	}
}


int main() {
	srand((unsigned)time(NULL));

	long long cnt = 0;
	int n = -1;
	cout << "11�A�Œ������A�m�胂�[�h�ɂ���ɂ�? yes�Ŋm�胂�[�h�ɂȂ�ɂ�" << endl;
	string mode;
	cin >> mode;

	//"yes"�����͂��ꂽ�ꍇ�̂�, 11�A�Œ������A�m�胂�[�h��
	bool flag_guarantee = false;
	if (mode == "yes") flag_guarantee = true;

	//"greedy"�����͂��ꂽ�ꍇ�̂�, �C�ӂ̃L�������o��܂ŃK�`�������������郂�[�h��
	if (mode == "greedy") {
		cout << "�B���R�}���h�ɂ�!" << endl;
		//�C�ӂ̃L�����̎w��
		string purpose;
		cout << "�~�����L�����������ɂ�" << endl;
		//���͂����L���������K�`�����ɑ��݂��Ȃ��ꍇ,�ē��͂����߂�
		while (true) {
			cin >> purpose;
			auto item_rare = find(rare.begin(), rare.end(), purpose);
			auto item_super = find(super.begin(), super.end(), purpose);
			auto item_uber = find(uber.begin(), uber.end(), purpose);
			auto item_legend = find(legend.begin(), legend.end(), purpose);

			if (item_rare == rare.end() && item_super == super.end() && item_uber == uber.end() && item_legend == legend.end()) {
				cout << "���̃L�����͒m��Ȃ��ɂ�" << endl;
				cout << "�~�����L������������x�����Ăɂ�" << endl;
			}
			else break;

		}
		cout << endl;
		int i = 0;
		while (true) {
			int iter_rare = generator_rare();
			string unit_now = generator_unit(iter_rare);
			cout << i + 1 << " : " << unit_now << endl;
			//11�A����1�񕪂���
			if ((i + 1) % 11 != 0) cnt += 150;
			//�C�ӂ̃L�������o��������,�o���Ȃ�I��
			if (unit_now == purpose) break;
			i++;
		}
	}

	else {
		cout << "����K�`���������������Ăɂ�" << endl;
		cin >> n;
		cout << n << "��K�`����!" << endl << endl;
	}

	for (int i = 0; i < n; i++) {
		//11�A�Œ������A�m�胂�[�h,�m��g��11�A�ڂȂ̂Ńl�R�J������͕s�v
		if (flag_guarantee && (i + 1) % 11 == 0) {
			cout << i + 1 << " : " << generator_unit(2) << " �m��g�ɂ�" << endl;
		}

		else {
			cout << i + 1 << " : " << generator_unit(generator_rare()) << endl;
			//11�A����1�񕪂���
			if ((i + 1) % 11 != 0) cnt += 150;
		}
	}
	cout << "������l�R�J���� " << cnt << "�ɂ�!" << endl;
}