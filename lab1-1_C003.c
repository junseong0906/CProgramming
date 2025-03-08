/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5���� ȣ�� �� �� ���尡 �ִ� ���� ã�Ƴ���. (���ϰ� 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // ���� ����� ����Ѵ�.

int main(){
	char mnames[10][20]; // ���л����(�ִ� 10��)
	int mroom[10];		// ���л���ܺ� ȣ�� ���� ���
	char wnames[10][20]; // ���л����(�ִ� 10��)
	int wroom[10];		// ���л���ܺ� ȣ�� ���� ���
	int person[2][5]={0};   // 2�� ���� 5�� ȣ���� ���� �ο� �� 
	int mcount=0, wcount=0; // �ο� �հ� (��, ��)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("��Ȱ�� ȣ�� ���� ���α׷�\n");
	printf("===========================================\n");
	while(1){
		printf("�޴� : 1.���л� ��� 2.���л� ��� 0.���� > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("���� �ʰ��Դϴ�. ��ϺҰ�!\n");
				continue;
			}
			printf("�л� �̸���? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s �л� %dȣ�� �����Ǿ����ϴ�.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("���� �ʰ��Դϴ�. ��ϺҰ�!\n");
				continue;
			}
			printf("�л� �̸���? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s �л� %dȣ�� �����Ǿ����ϴ�.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("��Ȱ�� ȣ�� ���� ����� ������ �����ϴ�.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){
// �� ���� ���� ������ �ڵ� ����
// �������� ���� ã�� �� �濡 2���� �ִ��� Ȯ���� �ؾ��ϹǷ�
// ���� ������ rand �Լ��� ���� ���� ���� ���� �� if���ǹ����� 2�� �̸��̸�
// 1�� �����ϵ��� �Ͽ� �������� ǥ��. ��ȯ���� 1ȣ �����̹Ƿ� +1�ؼ� ��ȯ

    int room;
    while (1) {
        room = rand() % 5; 
        if (persons[room] < 2) {
            persons[room]++;
            return room + 1;
        }
    }

}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// �ܼ��� �Էµ� �迭�� ���Ŀ� ���� ����ϴ� ���̹Ƿ� ���Ŀ� ���� �迭�� ��·�
// ���л� ���, ���л� ���, ȣ�Ǻ� ���� ��� ������ ���
    
    printf("\n���л� ��� (%d��)\n", mc);
    for (int i = 0; i < mc; i++) {
        printf("%d. %s [%dȣ]\n", i + 1, mn[i], mr[i]);
    }
    
    printf("\n���л� ��� (%d��)\n", wc);
    for (int i = 0; i < wc; i++) {
        printf("%d. %s [%dȣ]\n", i + 1, wn[i], wr[i]);
    }
    
    printf("\nȣ�Ǻ� ���� ���\n");
    for (int i = 1; i <= 5; i++) {
        printf("%dȣ :", 100 + i);
        for (int j = 0; j < mc; j++) {
            if (mr[j] == 100 + i) printf(" %s", mn[j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= 5; i++) {
        printf("%dȣ :", 200 + i);
        for (int j = 0; j < wc; j++) {
            if (wr[j] == 200 + i) printf(" %s", wn[j]);
        }
        printf("\n");
    }
}
