>>>today gloria said when self update axtu
rpm command is no longer available! axtu crashes too natrually.
I was confused at first, but soon we found, there are not all rpm packages in self.
And all are clear now. 
Let say lastest rpm depends on  lastest nspr, but if there is only old nspr on systerm rpm will break natrually!
that is because axtu self-update use --nodeps option!
