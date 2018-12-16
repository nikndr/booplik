#include "utils.h"
#include "Word.h"
#include <iostream>

using namespace std;

#include "CharFreqTable.h"
#include "TextEncoder.h"

unsigned int countWords(char *text)
{
	unsigned int counter = 0;
	unsigned int i = 0;
	while (text[i] != 0) {
		if (separator(text[i])) {
			++counter;
			if (separator(text[i+1]))
				++i;
		}
		++i;
	}
	return counter;
}

int main()
{
	char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
			"Integer maximus risus ut felis accumsan fringilla. Donec elementum "
			"eget ligula eget posuere. Duis at dolor quam. Integer vel tincidunt massa. "
			"Integer vitae leo tempor nisi vehicula suscipit at sit amet ex. "
			"Donec vel risus augue. Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
			"Morbi quis massa quis elit malesuada facilisis sit amet non tortor. "
			"Integer et nisi eu ex aliquet posuere. Nulla eu nulla wjkk enim. "
			"Quisque at quam condimentum, dapibus lorem nec, varius arcu. "
			"Suspendisse quis tincidunt sapien. Vestibulum pharetra sem lobortis ex aliquet, quis ultrices leo blandit. "
			"Phasellus erat nisl. Donec ut leo egestas, vestibulum ligula vel, finibus est."
			"Pellentesque neque orci, auctor vitae leo eget, efficitur pretium velit.Mauris at tortor dictum, congue."
			"Maecenas rutrum, nulla ut gravida faucibus, magna lorem egestas eros, id laoreet orci dolor eget eros."
			"Nunc eleifend sollicitudin bibendum.Ut vel hendrerit nunc zoo yuke yock yaw."
			"Aenean feugiat mi nisl.Ut interdum pretium libero, sit amet vestibulum augue volutpat nec.";
	TextEncoder enc(text);
	TextEncoder dec(enc.text());
	cout << dec.text();
}
