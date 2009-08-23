>>>one big update
now I have the following patches
<>
------- gui/axtu/classGui.cpp ----------------------------
index 6b0a12c..f923d79 100644
@@ -1656,6 +1656,10 @@ void classGui::SetPackageSummary(const char * strNVRA)
 		{
 			edtPackageSummary->append(result->summary);
 			edtPackageSummary->append(" \n");
+			edtPackageSummary->append("pppppppppppppppppp\n");
+			edtPackageSummary->append(*(result->requireName));
+			edtPackageSummary->append(*(result->requireVersion));
+			edtPackageSummary->append("ppppppppppppppppppp \n");
 			edtPackageSummary->append(result->shortDesp);
 			edtPackageSummary->moveCursor(QTextEdit::MoveHome, false);
 		}
</>
<>
 libs/classRpmEngine.cpp ---------------------------
index bbbde1d..f83bb69 100644
@@ -1315,7 +1320,7 @@ struct structRPMInfo *classRpmEngine::GetHeaderInfo(Header h, int k, int index /
 	int tag1[9] = { RPMTAG_NAME, RPMTAG_VERSION, RPMTAG_RELEASE,
 			RPMTAG_SIZE, RPMTAG_GROUP, RPMTAG_SUMMARY,
 			RPMTAG_DESCRIPTION, RPMTAG_ARCH, 1000004 };
-	int tag2[4] = { RPMTAG_REQUIRENAME, RPMTAG_REQUIREVERSION,
+	int tag2[4] = { RPMTAG_OBSOLETENAME, RPMTAG_OBSOLETEVERSION,
 			RPMTAG_PROVIDENAME, RPMTAG_PROVIDEVERSION };
 
 	rpmInfo = (struct structRPMInfo *)malloc(sizeo
</>

>and now the value of obsolete name and version are there for us, easily cleanly
