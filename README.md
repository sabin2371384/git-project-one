عملکرد کلی برنامه 👇👇👇
این کد یک سیستم مدیریت اطلاعات دانشجویی است که به کاربران اجازه می‌دهد:
1- اطلاعات شخصی دانشجویان را وارد کنند.
2- دروس آن‌ها را همراه با نمرات و تعداد واحدهایشان ثبت کنند.
3- معدل (GPA) دانشجو را محاسبه کنند.
4- کارنامه دانشجو را به‌صورت جدولی نمایش دهند.
کد از ساختارهای struct برای تعریف دانشجویان و دروس استفاده می‌کند و از vector برای ذخیره مجموعه‌ای از داده‌ها استفاده میکنه و در ادامه ابتدا از کاربر تعداد دانشجویان را می‌پرسد، سپس اطلاعات آن‌ها را گرفته و در نهایت کارنامه هر دانشجو را نمایش می‌دهد.
📌توضیح بخش های مختلف کد به صورت جزِیی تر : 
برنامه وارد main() می‌شود ,و سپس متغیر numStudents در حافظه ایجاد می‌شود. پیام "Enter number of students: " در خروجی (کنسول) چاپ می‌شود. در نهایت منتظر ورودی از کاربر می‌ماند و مقدار را در numStudents ذخیره می‌کند .
سپس یک آرایه داینامیک از نوع vector<Student> در حافظه ساخته می‌شود(این آرایه، تمام اطلاعات دانشجویان را در خود ذخیره خواهد کرد) و حالا حافظه کامپیوتر آماده نگهداری اطلاعات دانشجویان است. برنامه وارد حلقه for می‌شود و یک متغیر s از نوع Student در حافظه ساخته می‌شود
(این فرایند numStudents بار تکرار می‌شود.) 
 پیام "Enter information for student #X:" نمایش داده می‌شود. دستور cin.ignore(); از ورودی‌های قبلی صرف نظر می‌کند تا از مشکلات getline() جلوگیری کند و getline(cin, s.firstName); نام دانشجو را خوانده و در s.firstName ذخیره می‌کند ، getline(cin, s.lastName); نام خانوادگی را خوانده و در s.lastName ذخیره می‌کند 
 و به همین صورت .......
 در ادامه از کاربر تعداد دروس (numCourses) پرسیده شده و در متغیر مربوطه ذخیره می‌شود . cin.ignore(); برای حذف مقدار باقی‌مانده در cin استفاده شده تا ورودی بعدی دچار مشکل نشود . یک حلقه جدید برای دریافت اطلاعات دروس اجرا می‌شود.
در هر تکرار، سه متغیر برای نام درس، نمره و تعداد واحدها در حافظه ایجاد می‌شوند . پیام "Enter course name: " در خروجی چاپ می‌شود و نام درس از ورودی دریافت شده و در cname ذخیره می‌شود . در ادامه از کاربر نمره درس خواسته می‌شود. اگر مقدار ورودی صحیح نباشد یا خارج از محدوده ۰ تا ۲۰ باشد انوقت پیام خطا نمایش داده می‌شود.
(این مکانیزم از ورود اطلاعات نامعتبر جلوگیری می‌کند) در مرحله بعد تعداد واحد دریافت شده و در cunits ذخیره می‌شود ، اگر مقدار منفی یا صفر باشد دو اتفاق خواهئ افتاد 1- برنامه خطا نمایش می‌دهد یا 2- از کاربر مقدار معتبر می‌خواهد (این بررسی مانع از ورود تعداد واحد نامعتبر می‌شود) بعد تابع addCourse() اجرا شده و درس جدید به vector دروس دانشجو اضافه می‌شود.
تابع displayTranscript() اجرا شده و اطلاعات دانشجو نمایش داده می‌شود ، وقتی همه دانشجویان پردازش شدند، main() به انتها می‌رسد و در اخر مقدار 0 به سیستم‌عامل بازگردانده می‌شود که نشان‌دهنده اجرای موفقیت‌آمیز برنامه است.
امیدوارم توضیحات واضح بوده باشه 😊











