#include "FileTokenizer.h"

FTokenizer::FTokenizer(char* fname) {
	_f.open(fname);
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
	if (!_f.eof()) {
		_pos += MAX_BLOCK;
		_f.read(text, MAX_BLOCK-1);
		text[_f.gcount()] = '\0';
		_blockPos = _pos - MAX_BLOCK;
		this->_stk.set_string(text);
		_more = true;
		return true;
	} else {
		_more = false;
		return false;
	}
}

FTokenizer& operator >> (FTokenizer& f, Token& t) {
	if (f._blockPos == f._pos) {
		f.get_new_block();
	}
	string temp = "";
	f._stk >> t;
	temp = t.token_str();
	f._blockPos += temp.length();

	return f;
}


