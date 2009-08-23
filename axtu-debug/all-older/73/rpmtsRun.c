"06/25/09 18:13:15 classRpmEngine Error is occured in rpmtsRun()"

Now let's see this error
>>>
1.in rpm engine we have 
rc = rpmtsRun(m_rpmTs, NULL, (rpmprobFilterFlags)probFilter);
...
 else if(rc == -1)
        {
                m_Logger->WriteLog_char(ERROR_LOG, MYSELF_NAME,"Error is occured in rpmtsRun()", NULL);
                rpmpsFree(probs);
                return -1;
        }
2. so error is in rpmtsRun, which is part of rpm lib
in int rpmtsRun()
I see
<>
/* XXX programmer error segfault avoidance. */  
if (rpmtsNElements(ts) <= 0)
        return -1;
</>
so it is due to a segfault, haha

3. 
<>
int rpmtsNElements(rpmts ts)
{
    int nelements = 0;
    if (ts != NULL && ts->order != NULL) {
        nelements = ts->orderCount;
    }
    return nelements;
}
</>

4. the class "ts" is really really complex.
