===
classAuthen.cpp

classAuthen::RunAuthApp()
{
        nSystemReturn = system(strCmdPrefix.c_str());
}
 
classAuthen::CheckAuthen()
{
RunAuthApp()
}

===
classNetwork.cpp
int classNetwork::CheckAuthen(bool bAct)
{
	nRet=m_clsAuth->CheckAuthen();
}

===
classGui::classGui()
{
	m_refNetwork->CheckAuthen();

}
