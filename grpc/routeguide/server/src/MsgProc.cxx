#include "MsgProc.h"
#include "ResponseHandler.h"

void pro::AsyncGreeterProc::proceed()
{
	if (_status == CREATE) {
		_status = PROCESS;
		_service->RequestsayHello(&_ctx, &_req, &_responder, _cq, _cq, this);
	} else if (_status == PROCESS) {
		new AsyncGreeterProc(_service, _cq);
		_rsp.set_message(pro::getResponseHandler()->getResponse(_req.name()));
		_status = FINISH;
		_responder.Finish(_rsp, Status::OK, this);
	} else {
		GPR_ASSERT(_status == FINISH);
		delete this;
	}
}

