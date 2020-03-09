#include "FileTokenizer.h"

FTokenizer::FTokenizer(char* fname) {
	_f.open(fname);
	_f.is_open();
	_pos = 0;
	_blockPos = 0;
	_more = false;
}

bool FTokenizer::more() {
	return _more;
}

int FTokenizer::pos() {
	return _pos;
}

int FTokenizer::block_pos() {
	return _blockPos;
}

bool FTokenizer::get_new_block() {
	char* text = new char[MAX_BLOCK];
	if (_f.is_open()) {
		_pos += MAX_BLOCK;
		_f.read(text, MAX_BLOCK-1);
		text[MAX_BLOCK - 1] = '\0';
		_blockPos = _pos - MAX_BLOCK;
		return true;
	} else {
		return false;
	}
}

FTokenizer& operator >> (FTokenizer& f, Token& t) {
	string temp = "";
	while (temp.empty() && f.get_new_block()) {
		f._stk >> t;
		temp = t.token_str();
	}
	return f;
}


