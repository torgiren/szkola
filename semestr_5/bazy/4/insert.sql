-- tabMoon
INSERT INTO i9fabryk.universe.tabMoon (id, name, period, distance, idMoon, idPlanet) VALUES (nextval('seq_id'), 'Moon_1',
'10.01', '100.01', '1', '1');
INSERT INTO i9fabryk.universe.tabMoon (id, name, period, distance, idMoon, idPlanet) VALUES (nextval('seq_id'), 'Moon_2',
'30.03', '200.02', '1', null);
INSERT INTO i9fabryk.universe.tabMoon (id, name, period, distance, idMoon, idPlanet) VALUES (nextval('seq_id'), 'Moon_3',
'50.05', '300.03', '2', null);
INSERT INTO i9fabryk.universe.tabMoon (id, name, period, distance, idMoon, idPlanet) VALUES (nextval('seq_id'), 'Moon_4',
'70.07', '400.04', '4', '4');
INSERT INTO i9fabryk.universe.tabMoon (id, name, period, distance, idMoon, idPlanet) VALUES (nextval('seq_id'), 'Moon_5',
'90.09', '500.05', '5', '5');
-- tabPlanet
INSERT INTO i9fabryk.universe.tabPlanet (id, idSystem, name, period, distance, url) VALUES (nextval('seq_id'), null, 'Planet1',
'100', '1000.01', 'http://planet1.org');
INSERT INTO i9fabryk.universe.tabPlanet (id, idSystem, name, period, distance, url) VALUES (nextval('seq_id'), null, 'Planet2',
'200', '5000.01', 'http://planet2.org');
INSERT INTO i9fabryk.universe.tabPlanet (id, idSystem, name, period, distance, url) VALUES (nextval('seq_id'), null, 'Planet3',
'300', '9000.01', 'http://planet3.org');
INSERT INTO i9fabryk.universe.tabPlanet (id, idSystem, name, period, distance, url) VALUES (nextval('seq_id'), null, 'Planet4',
'400', '13000.01', 'http://planet4.org');
INSERT INTO i9fabryk.universe.tabPlanet (id, idSystem, name, period, distance, url) VALUES (nextval('seq_id'), '1', 'Planet5',
'500', '17000.01', 'http://planet5.org');
-- tabplanet2sun
INSERT INTO i9fabryk.universe.tabplanet2sun (idSun, idPlanet) VALUES ('1', '1');
INSERT INTO i9fabryk.universe.tabplanet2sun (idSun, idPlanet) VALUES ('2', '1');
INSERT INTO i9fabryk.universe.tabplanet2sun (idSun, idPlanet) VALUES ('3', '2');
INSERT INTO i9fabryk.universe.tabplanet2sun (idSun, idPlanet) VALUES ('4', '3');
INSERT INTO i9fabryk.universe.tabplanet2sun (idSun, idPlanet) VALUES ('5', '4');
-- tabSun
INSERT INTO i9fabryk.universe.tabSun (id, idSystem, name) VALUES ('1', '1', 'Sun_1');
INSERT INTO i9fabryk.universe.tabSun (id, idSystem, name) VALUES ('2', '2', 'Sun_2');
INSERT INTO i9fabryk.universe.tabSun (id, idSystem, name) VALUES ('3', '2', 'Sun_3');
INSERT INTO i9fabryk.universe.tabSun (id, idSystem, name) VALUES ('4', '4', 'Sun_4');
INSERT INTO i9fabryk.universe.tabSun (id, idSystem, name) VALUES ('5', '5', 'Sun_5');
-- tabSystem
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('1', '1', 'System_1', '2011-01-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('2', '2', 'System_2', '2012-02-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('3', '3', 'System_3', '2013-03-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('4', '4', 'System_4', '2014-04-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('5', '5', 'System_5', '2015-05-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('6', '1', 'System_6', '2011-01-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('7', '2', 'System_7', '2012-02-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('8', '2', 'System_8', '2013-03-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('9', '2', 'System_9', '2014-04-01 i9fabryk');
INSERT INTO i9fabryk.universe.tabSystem (id, idUnivers, name, discStamp) VALUES ('10', '5', 'System_10', '2015-05-01 i9fabryk');
-- tabUniverse
INSERT INTO i9fabryk.universe.tabUniverse (id, name) VALUES ('1', 'UniversA_1');
INSERT INTO i9fabryk.universe.tabUniverse (id, name) VALUES ('2', 'UniversA_2');
INSERT INTO i9fabryk.universe.tabUniverse (id, name) VALUES ('3', 'UniversA_3');
INSERT INTO i9fabryk.universe.tabUniverse (id, name) VALUES ('4', 'UniversA_4');
INSERT INTO i9fabryk.universe.tabUniverse (id, name) VALUES ('5', 'UniversA_5');

