create schema universe;
create domain domStartUpEndNum as text
	constraint valid_value check(value ~ '^[A-Z].*[0-9]$' or value ~ '^[A-Z].*_[0-9]$');
create domain domUrl as text
	constraint valid_value check(value ~ '^http[s]?://.*.org$');
create domain domStamp as text
	constraint valud_value check(value ~ '^[0-9]{4}-[0-9]{2}-[0-9]{2} .*$');
create table universe.tabuniverse(id INT PRIMARY KEY, name domStartUpEndNum);
create table universe.tabmoon(id int PRIMARY KEY, name domStartUpEndNum, period DECIMAL(5,2), DISTANCE DECIMAL(10,2), IDMOON INT, IDPLANET INT);
create table universe.tabplanet(id int DEFAULT nextval('seq_id'), idsystem int, name domStartUpEndNum, period DECIMAL(5,2), distance DECIMAL(10,2), url domUrl);
create table universe.tabplanet2sun(idsun int PRIMARY KEY, idplanet int NOT NULL);
create table universe.tabsun(id int PRIMARY KEY, idsystem int not null, name domStartUpEndNum);
create table universe.tabsystem(id int PRIMARY KEY, idunivers int not null, name domStartUpEndNum, discstamp domStamp);
create unique index universenameindex on universe.tabuniverse(name);
create unique index moonnameindex on universe.tabmoon(name);
create unique index planetnameindex2 on universe.tabplanet(name);
create unique index systemnameindex2 on universe.tabsystem(name);
create unique index sunnameindex on universe.tabsun(name);
create sequence seq_id start 1;

