CREATE TABLE Museum (
    museum_id   NUMBER(10)    PRIMARY KEY,
    museum_name VARCHAR2(100)
);

CREATE TABLE Museum_Object (
    object_id         VARCHAR2(50)  PRIMARY KEY,
    museum_id         NUMBER(10)    REFERENCES Museum(museum_id),
    object_name       VARCHAR2(200),
    culture           VARCHAR2(100),
    country_of_origin VARCHAR2(100),
    geographical_ref  VARCHAR2(100),
    dimensions        VARCHAR2(100),
    length_cm         NUMBER(10,2),
    width_cm          NUMBER(10,2),
    height_cm         NUMBER(10,2),
    medium_material   VARCHAR2(200),
    acquisition_date  VARCHAR2(50),
    acq_date          VARCHAR2(10),
    acq_month         VARCHAR2(10),
    acq_year          VARCHAR2(10),
    acquisition_type  VARCHAR2(100),
    acquirer_name     VARCHAR2(200)
);

INSERT INTO Museum VALUES (1, 'Museum 1');
INSERT INTO Museum VALUES (2, 'Museum 2');

INSERT ALL
    INTO Museum_Object VALUES (
        'RV-1184-421', 1, 'boog',   'Braziliaans', 'Brazil', NULL, NULL, NULL, NULL, NULL,  'hout, veren',    '1898-08-01', '01', '08', '1898',   'Verwerving', 'Nationale Tentoonstelling van vrouwen-arbeid'
    )
    INTO Museum_Object VALUES (
        'RV-1184-422', 1, 'Trofee', 'Jivaro', 'Ecuador/Peru', NULL,  '10x7cm, 55cm(haar)', 10.0, 7.0, NULL,    'huid (menselijk), hout, katoen, mendenhaar, touw, huid- en velbewerking',  '1898-08-01', '01', '08', '1898', 'Verwerving', 'Amelia burggravin van Cavalcanti'
    )
    INTO Museum_Object VALUES (
        'RV-1194-1', 1, 'kan',  'Antilliaans', 'Antilles', NULL,  NULL, NULL, NULL, NULL,   'aardewerk',   '1898-09-01', '01', '09', '1898',  'Verwerving', 'Nationale Tentoonstelling van vrouwen-arbeid'
    )
    INTO Museum_Object VALUES (
        'RV-1194-2', 1, 'koelkruik',    'Antilliaans', 'Antilles', NULL,    NULL, NULL, NULL, NULL, 'aardewerk', '1898-09-01', '01', '09', '1898',    'Verwerving', 'Nationale Tentoonstelling van vrouwen-arbeid'
    )
    INTO Museum_Object VALUES (
        'RV-1194-3', 1, 'strottenhoofd',    'Surinaams', 'Suriname', NULL,  NULL, NULL, NULL, NULL,   'strottenhoofd van aap',   '1898-09-01', '01', '09', '1898',  'Verwerving', 'Nationale Tentoonstelling van vrouwen-arbeid'
    )
    INTO Museum_Object VALUES (
        'RV-1194-4', 1, 'beeld/vogel',  'Karaiben', 'Caribbean', NULL,    '9.3x11.3cm', 9.3, 11.3, NULL,  'aardewerk',  '1898-09-01', '01', '09', '1898', 'Verwerving', 'Nationale Tentoonstelling van vrouwen-arbeid'
    )
    INTO Museum_Object VALUES (
        'RV-1194-5', 1, 'lendendoek',   'Saamaka', 'Suriname', NULL,   '96.5x69cm', 96.5, 69.0, NULL, 'katoen',    '1898-09-01', '01', '09', '1898',   'Verwerving', 'Nationale Tentoonstelling van vrouwen-arbeid'
    )
    INTO Museum_Object VALUES (
        'RV-1194-6', 1, 'doek', 'Marrons', 'Suriname', NULL, NULL, NULL, NULL, NULL,  NULL, '1898-09-01', '01', '09', '1898',    'Verwerving', 'Nationale Tentoonstelling van vrouwen-arbeid'
    )
    INTO Museum_Object VALUES (
        'RV-1200-18', 1, 'knots',   'Guyanaans', 'Guyana', NULL,   '68.7x8.3x2.2cm', 68.7, 8.3, 2.2,  'hout',   '1898-11-01', '01', '11', '1898',  'Verwerving', 'Venduehuis der Notarissen'
    )
    INTO Museum_Object VALUES (
        'IV-Ca-4577', 2, 'Steinbeilklinge', 'Guatemala', 'Guatemala', 'St. Lucas',   '9.5x4x2.5cm', 9.5, 4.0, 2.5,  'Stein',  '1877', NULL, NULL, '1877',   'Acquisition', 'Wilhelm Schleiden'
    )
    INTO Museum_Object VALUES (
        'IV-Ca-4578', 2, 'Steinfigur',  'Guatemala', 'Guatemala', 'St. Lucas',    '14x5.2x6cm', 14.0, 5.2, 6.0,   'Stein',   '1877', NULL, NULL, '1877',    'Acquisition', 'Wilhelm Schleiden'
    )
    INTO Museum_Object VALUES (
        'IV-Ca-4579', 2, 'Steinaufsatz',    'Guatemala', 'Guatemala', 'Antigua',    '25.1x22.6x18cm', 25.1, 22.6, 18.0, 'Stein', '1877', NULL, NULL, '1877',  'Acquisition', 'Geppy Herrera'
    )
    INTO Museum_Object VALUES (
        'IV-Ca-4580', 2, 'Steinkopf',   'Guatemala', 'Guatemala', 'Neu Guatemala', '17x13x9.5cm', 17.0, 13.0, 9.5,  'Stein',  NULL, NULL, NULL, NULL,   'Acquisition', 'Hermann Albert Schumacher'
    )
    INTO Museum_Object VALUES (
        'IV-Ca-4581', 2, 'Reibstein',   'Guatemala', 'Guatemala', 'Utatlan (Santa Cruz del Quiche)',   '12x6x5.7cm', 12.0, 6.0, 5.7,  'Stein',  '1878', NULL, NULL, '1878',   'Acquisition', 'Adolf Bastian'
    )
SELECT * FROM dual;

COMMIT;