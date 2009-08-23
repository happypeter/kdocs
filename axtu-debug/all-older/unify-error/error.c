http://bugzilla.asianux.com/show_bug.cgi?id=3619
MT -Error message is not unified.
#define URL_ERR_MSG		CONNECT_ERR_MSG
>>> Anyway we want 
---"Cannot connect with the TSN server."
+++"Required data were not found on the server."
服務器端所需數據未找到。
服务器端所需数据未找到。

"서버로부터 필요한 정보를 찾을 수 없습니다."
"要求されたデータがサーバーに見つかりませんでした。"

>>>
* including this one
--- strErr = tr("Cannot connect with the TSN Server. See %1%2").arg(m_strLogPath, ERROR_LOG_FILE);
+++"Required data were not found on the server. See %1%2"
服務器端所需數據未找到。見%1%2
服务器端所需数据未找到。见%1%2
"要求されたデータがサーバーに見つかりませんでした。%1%2を参照してください。"
"요청된 데이터가 서버에 존재하지 않습니다. %1%2를 보십시오."
