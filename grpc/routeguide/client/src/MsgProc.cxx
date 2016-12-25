#include "MsgProc.h"

void pro::GreeterProc::process()
{
	if (_status.ok()) {
		_message = _rsp.message();
	}
	
	_proc->onRsp(_status.error_code(), _userdata, _message);
	delete this;
}

