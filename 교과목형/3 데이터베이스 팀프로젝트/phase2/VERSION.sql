create table VERSION (
	Movie_id INT references MOVIE(movie_id),
	Version_id INT NOT NULL,
	Region VARCHAR(50),
	Lanuage VARCHAR(50),
	Local_title VARCHAR(100),
	Is_original boolean,
	Start_year DATE,
	primary key(Movie_id, Version_id)
);

insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (158, 1, 'KR', 'Korean', 'Customer-focused asynchronous budgetary management', true, '2006-06-19');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (158, 2, 'US', 'Engilsh', 'Virtual clear-thinking internet solutio', false, '2009-09-04');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (158, 3, 'PT', 'Filipino', 'Re-engineered background archive', false, '2011-09-12');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (190, 1, 'US', 'Engilsh', 'Multi-channelled directional circuit', false, '2020-03-07');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (190, 2, 'KR', 'Korean', 'Centralized grid-enabled adapter', false, '2020-02-22');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (190, 3, 'PH', 'Filipino', 'Sharable national capability', true, '1980-03-10');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (188, 1, 'ID', 'Nepali', 'Cloned static pricing structure', false, '2034-04-21');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (188, 2, 'CN', 'Dutch', 'Sharable tangible solution', true, '2033-06-24');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (188, 3, 'GE', 'Bosnian', 'Function-based global adapter', false, '2035-03-22');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (12, 1, 'AF', 'Pashto', 'Reduced encompassing hardware', false, '2011-11-11');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (12, 2, 'CO', 'Kurdish', 'Balanced multi-state database', true, '2006-12-11');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (12, 3, 'JP', 'Polish', 'Multi-lateral actuating challenge', false, '2024-09-01');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (167, 1, 'KR', 'Korean', 'Streamlined uniform intranet', true, '2007-10-15');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (167, 2, 'CN', 'Kannada', 'Synchronised solution-oriented challenge', false, '2015-08-14');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (167, 3, 'EG', 'Catalan', 'Fundamental scalable collaboration', false, '2016-11-12');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (75, 1, 'SE', 'Hindi', 'Managed eco-centric internet solution', true, '2030-09-30');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (75, 2, 'RU', 'Sotho', 'Virtual clear-thinking internet solution', false, '2031-01-01');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (75, 3, 'CN', 'Engilsh', 'Vision-oriented zero tolerance interface', false, '2033-02-12');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (75, 4, 'AL', 'Swedish', 'Profit-focused upward-trending interface', false, '2035-09-11');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (236, 1, 'PT', 'Tok Pisin', 'Inverse 6th generation open architecture', true, '1991-02-06');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (236, 2, 'FI', 'Pashto', 'Exclusive bandwidth-monitored benchmark', false, '1995-04-06');
insert into VERSION (Movie_id, Version_id, Region, Lanuage, Local_title, Is_original, Start_year) values (236, 3, 'CN', 'Azeri', 'Managed system-worthy architecture', false, '1999-09-09');