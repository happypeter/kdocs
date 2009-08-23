
FYI, WTEC registraion page.

http://www.wtec.co.th/asianux_registration.html


---------- Forwarded message ----------
From: Phiroon Phihakendr <Phiroon@wtec.co.th>
Date: 2009/5/4
Subject: RE: URL of TSN WTEC .
To: "Jung, SeungHwan (Hwanii)" <hwanii.jung@asianux.com>
참조: Jaykay Kim <jkkim@asianux.com>, Echo Mao <echo.mao@asianux.com>,
Xue Hong <hong.xue@asianux.com>, Open Source
<opensourcewtec@wtec.co.th>, Senee Hongsubchat <senee@wtec.co.th>,
Wimol Sonsittiwiwat <wimol@wtec.co.th>, Sornchai Phenkrob
<sornchai@wtec.co.th>, Peter Wang <peter.wang@asianux.com>


Hi Hwanii,



You can use http://www.wtec.co.th/asianux_registration.html for the
registration page.



I have looked at the sample pages and will ask them to make this html
page.  If there are any technical questions, we will let you know.



Thanks,

Phiroon



From: medolika@gmail.com [medolika@gmail.com] On Behalf Of
Jung, SeungHwan (Hwanii)
Sent: Monday, April 27, 2009 10:45 AM
To: Phiroon Phihakendr
Cc: Jaykay Kim; Echo Mao; Xue Hong; Open Source; Senee Hongsubchat;
Wimol Sonsittiwiwat; Sornchai Phenkrob; Peter Wang
Subject: Re: URL of TSN WTEC .



Phiroon,

We need the URL of the registration web page. If you are going to
make one, could you determine the URL and let us know?

When user connect to TSN WTEC server with AXTU before signing
up and registering their product in the web site, AXTU will lead the
user to the website (for them to register their product).

For AXTU to do this, the URL is needed.

Regards,
Hwanii

2009/4/27 Jung, SeungHwan (Hwanii) <hwanii.jung@asianux.com>

Hello Phiroon,

Actually each company has their own registration web page.
If you want, you can refer to the TSN Local design.

About the DB fields, you should have the followings data.

1. product number
 - Asianux Product number.

2. userID

3. passwd

4. reg_date
    - date user registered the product.

5. exp_date
    - data the product service should finish
     (you and update this date)


You can add more fields. But these are all AXTU Local needs.



FYI, you might want to have a look at those registration web page :

HS = http://www.asianux.co.kr/register.php
ML = http://www.miraclelinux.com/user
RF = http://www.redflag-linux.com/ppd/product_user/register1.php


Regards,
Hwanii



2009/4/13 Phiroon Phihakendr <Phiroon@wtec.co.th>

Hi Hwanii,

Yes, you can use both

www.wtec.co.th/tsn/tsn_local

and

update.wtec.co.th/auth/src/authentication.php

We don't have a customer registration web page but we can make one.  Do you
have an example to show us so we can have the same look and feel.  I think
the form fields are the most important thing.

Thanks,
Phiroon

-----Original Message-----
From: medolika@gmail.com [medolika@gmail.com] On Behalf Of Jung,
SeungHwan (Hwanii)

Sent: 2009-04-13 17:01
To: Phiroon Phihakendr
Cc: Jaykay Kim; Echo Mao; Xue Hong; Open Source; Senee Hongsubchat; Wimol
Sonsittiwiwat; Sornchai Phenkrob

Subject: Re: URL of TSN WTEC .

Phiroon,

So we can use below URL  for TSN WTEC URL.
 "www.wtec.co.th/tsn/tsn_local"

Ad we can use below URL for Authentication Server. URL
 "update.wtec.co.th/auth/src/authentication.php"

One question, what is your customer registration web page? (No. 3 bellow)
If you don't have one, please let us know. We need to find a way.


Regards,
Hwanii


2009/4/13 Phiroon Phihakendr <Phiroon@wtec.co.th>:
> Hi Hwanii,
>
> Our URL is www.wtec.co.th.
>
> Thanks,
> Phiroon
>
> -----Original Message-----
> From: medolika@gmail.com [medolika@gmail.com] On Behalf Of Jung,
> SeungHwan (Hwanii)
> Sent: 2009-04-13 11:58
> To: Phiroon Phihakendr; Open Source; Senee Hongsubchat; Wimol
Sonsittiwiwat;
> Sornchai Phenkrob
> Cc: Jaykay Kim; Echo Mao; Xue Hong
> Subject: URL of TSN WTEC .
>
> Phiroon,
>
> Could you tell us the URL of WTEC please?
> We need three URLs as followings in order to develop AXTU(Updater)
> and to intall TSN Local
>
>
> 1. Authentications Server URL
>  - https://update.WTEC_URL/auth/src/authentication.php
> ex) update.asianux.co.kr/auth/src/authentication.php
>
>
> 2. TSN Local(WTEC) URL
>  - https://WTEC_URL/tsn_local
>
> ex) www.asianux.co.kr/tsn/tsn_local/
>
>
> 3. User registration page.
>  - User registration page for your customer.
> ex) www.redflag-linux.com/ppd/product_user/register1.php
>
>
> Regards,
> Hwanii
>



--
Hwanii

Manager
Software Maintenance Team
Asianux


