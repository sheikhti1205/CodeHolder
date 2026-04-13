/* =========================================================
   STEP 0: RAW LOADER TABLE
   This mirrors the Excel exactly as-is.
   This is NOT the final ER schema.
   ========================================================= */

begin
   execute immediate 'DROP TABLE raw_sheet CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/

create table raw_sheet (
   drug_name                      varchar2(500),
   side_effect_1                  varchar2(500),
   side_effect_2                  varchar2(500),
   side_effect_3                  varchar2(500),
   side_effect_4                  varchar2(500),
   side_effect_5                  varchar2(500),
   interacts_with_1               varchar2(500),
   interacts_with_2               varchar2(500),
   interacts_with_3               varchar2(500),
   disease_name                   varchar2(1000),
   disease_category               varchar2(500),
   drug_category                  varchar2(500),
   product_name                   varchar2(500),
   company_name                   varchar2(500),
   clinical_trial_title           varchar2(1000),
   clinical_trial_start_date      date,
   clinical_trial_completion_date date,
   clinical_trial_participants    number,
   clinical_trial_status          varchar2(100),
   clinical_trial_condition_1     varchar2(1000),
   clinical_trial_condition_2     varchar2(1000),
   clinical_trial_address_1       varchar2(1000),
   clinical_trial_institution     varchar2(1000),
   clinical_trial_address_2       varchar2(1000),
   clinical_trial_main_researcher varchar2(500),
   clinical_trial_condition_3     varchar2(1000)
);

/* =========================================================
   IMPORTANT:
   Import the Excel sheet EXACTLY into raw_sheet.
   Do not alter values.
   In Oracle SQL Developer:
   Right click raw_sheet -> Import Data -> choose the xlsx file
   and map the columns in the exact same order.
   ========================================================= */


/* =========================================================
   STEP 1: FINAL TABLES THAT FOLLOW THE ER DIAGRAM
   No extra final-schema attributes are added.
   ========================================================= */

begin
   execute immediate 'DROP TABLE conducted_by CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE focuses_on CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE studies CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE produced_by CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE is_marketed_as CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE treats CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE drug_interacts_with CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE has_side_effect CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE clinical_trial CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE researcher CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE company CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE product CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE side_effects CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE disease CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/
begin
   execute immediate 'DROP TABLE drug CASCADE CONSTRAINTS';
exception
   when others then
      null;
end;
/

create table drug (
   drug_name     varchar2(500) primary key,
   drug_category varchar2(500)
);

create table disease (
   disease_name     varchar2(1000) primary key,
   disease_category varchar2(500)
);

create table side_effects (
   side_effect_name varchar2(500) primary key
);

create table product (
   product_name varchar2(500) primary key
);

create table company (
   company_name varchar2(500) primary key
);

create table researcher (
   main_researcher varchar2(500) primary key
);

create table clinical_trial (
   clinical_trial_title           varchar2(1000) primary key,
   clinical_trial_start_date      date,
   clinical_trial_completion_date date,
   clinical_trial_participants    number,
   clinical_trial_status          varchar2(100),
   clinical_trial_condition       varchar2(1000),
   clinical_trial_address         varchar2(1000),
   clinical_trial_institution     varchar2(1000)
);

create table has_side_effect (
   drug_name        varchar2(500),
   side_effect_name varchar2(500),
   primary key ( drug_name,
                 side_effect_name ),
   foreign key ( drug_name )
      references drug ( drug_name ),
   foreign key ( side_effect_name )
      references side_effects ( side_effect_name )
);

create table drug_interacts_with (
   drug_name                varchar2(500),
   interacts_with_drug_name varchar2(500),
   primary key ( drug_name,
                 interacts_with_drug_name ),
   foreign key ( drug_name )
      references drug ( drug_name ),
   foreign key ( interacts_with_drug_name )
      references drug ( drug_name )
);

create table treats (
   drug_name    varchar2(500),
   disease_name varchar2(1000),
   primary key ( drug_name,
                 disease_name ),
   foreign key ( drug_name )
      references drug ( drug_name ),
   foreign key ( disease_name )
      references disease ( disease_name )
);

create table is_marketed_as (
   drug_name    varchar2(500),
   product_name varchar2(500),
   primary key ( drug_name,
                 product_name ),
   foreign key ( drug_name )
      references drug ( drug_name ),
   foreign key ( product_name )
      references product ( product_name )
);

create table produced_by (
   product_name varchar2(500),
   company_name varchar2(500),
   primary key ( product_name,
                 company_name ),
   foreign key ( product_name )
      references product ( product_name ),
   foreign key ( company_name )
      references company ( company_name )
);

create table studies (
   drug_name            varchar2(500),
   clinical_trial_title varchar2(1000),
   primary key ( drug_name,
                 clinical_trial_title ),
   foreign key ( drug_name )
      references drug ( drug_name ),
   foreign key ( clinical_trial_title )
      references clinical_trial ( clinical_trial_title )
);

create table conducted_by (
   clinical_trial_title           varchar2(1000),
   clinical_trial_main_researcher varchar2(500),
   primary key ( clinical_trial_title,
                 clinical_trial_main_researcher ),
   foreign key ( clinical_trial_title )
      references clinical_trial ( clinical_trial_title ),
   foreign key ( clinical_trial_main_researcher )
      references researcher ( main_researcher )
);

create table focuses_on (
   clinical_trial_title varchar2(1000),
   disease_name         varchar2(1000),
   primary key ( clinical_trial_title,
                 disease_name ),
   foreign key ( clinical_trial_title )
      references clinical_trial ( clinical_trial_title ),
   foreign key ( disease_name )
      references disease ( disease_name )
);


/* =========================================================
   STEP 2: INSERT INTO FINAL ER TABLES FROM raw_sheet
   ========================================================= */

insert into drug (
   drug_name,
   drug_category
)
   select distinct drug_name,
                   drug_category
     from raw_sheet
    where drug_name is not null;

insert into disease (
   disease_name,
   disease_category
)
   select distinct disease_name,
                   disease_category
     from raw_sheet
    where disease_name is not null;

/* Clinical trial conditions are also used in FOCUSES ON.
   To keep those values without changing the final schema,
   put them into DISEASE if they are not already there. */
insert into disease (
   disease_name,
   disease_category
)
   select condition_name,
          null
     from (
      select distinct clinical_trial_condition_1 as condition_name
        from raw_sheet
      union
      select distinct clinical_trial_condition_2 as condition_name
        from raw_sheet
      union
      select distinct clinical_trial_condition_3 as condition_name
        from raw_sheet
   )
    where condition_name is not null
      and condition_name not in (
      select disease_name
        from disease
   );

insert into side_effects ( side_effect_name )
   select distinct side_effect_name
     from (
      select side_effect_1 as side_effect_name
        from raw_sheet
      union
      select side_effect_2 as side_effect_name
        from raw_sheet
      union
      select side_effect_3 as side_effect_name
        from raw_sheet
      union
      select side_effect_4 as side_effect_name
        from raw_sheet
      union
      select side_effect_5 as side_effect_name
        from raw_sheet
   )
    where side_effect_name is not null;

insert into product ( product_name )
   select distinct product_name
     from raw_sheet
    where product_name is not null;

insert into company ( company_name )
   select distinct company_name
     from raw_sheet
    where company_name is not null;

insert into researcher ( main_researcher )
   select distinct clinical_trial_main_researcher
     from raw_sheet
    where clinical_trial_main_researcher is not null;

insert into clinical_trial (
   clinical_trial_title,
   clinical_trial_start_date,
   clinical_trial_completion_date,
   clinical_trial_participants,
   clinical_trial_status,
   clinical_trial_condition,
   clinical_trial_address,
   clinical_trial_institution
)
   select distinct clinical_trial_title,
                   clinical_trial_start_date,
                   clinical_trial_completion_date,
                   clinical_trial_participants,
                   clinical_trial_status,
                   clinical_trial_condition_1,
                   clinical_trial_address_1,
                   clinical_trial_institution
     from raw_sheet
    where clinical_trial_title is not null;

insert into has_side_effect (
   drug_name,
   side_effect_name
)
   select distinct drug_name,
                   side_effect_name
     from (
      select drug_name,
             side_effect_1 as side_effect_name
        from raw_sheet
      union all
      select drug_name,
             side_effect_2 as side_effect_name
        from raw_sheet
      union all
      select drug_name,
             side_effect_3 as side_effect_name
        from raw_sheet
      union all
      select drug_name,
             side_effect_4 as side_effect_name
        from raw_sheet
      union all
      select drug_name,
             side_effect_5 as side_effect_name
        from raw_sheet
   )
    where drug_name is not null
      and side_effect_name is not null;

insert into drug_interacts_with (
   drug_name,
   interacts_with_drug_name
)
   select distinct drug_name,
                   interacts_with_drug_name
     from (
      select drug_name,
             interacts_with_1 as interacts_with_drug_name
        from raw_sheet
      union all
      select drug_name,
             interacts_with_2 as interacts_with_drug_name
        from raw_sheet
      union all
      select drug_name,
             interacts_with_3 as interacts_with_drug_name
        from raw_sheet
   )
    where drug_name is not null
      and interacts_with_drug_name is not null;

insert into treats (
   drug_name,
   disease_name
)
   select distinct drug_name,
                   disease_name
     from raw_sheet
    where drug_name is not null
      and disease_name is not null;

insert into is_marketed_as (
   drug_name,
   product_name
)
   select distinct drug_name,
                   product_name
     from raw_sheet
    where drug_name is not null
      and product_name is not null;

insert into produced_by (
   product_name,
   company_name
)
   select distinct product_name,
                   company_name
     from raw_sheet
    where product_name is not null
      and company_name is not null;

insert into studies (
   drug_name,
   clinical_trial_title
)
   select distinct drug_name,
                   clinical_trial_title
     from raw_sheet
    where drug_name is not null
      and clinical_trial_title is not null;

insert into conducted_by (
   clinical_trial_title,
   clinical_trial_main_researcher
)
   select distinct clinical_trial_title,
                   clinical_trial_main_researcher
     from raw_sheet
    where clinical_trial_title is not null
      and clinical_trial_main_researcher is not null;

insert into focuses_on (
   clinical_trial_title,
   disease_name
)
   select distinct clinical_trial_title,
                   disease_name
     from (
      select clinical_trial_title,
             clinical_trial_condition_1 as disease_name
        from raw_sheet
      union all
      select clinical_trial_title,
             clinical_trial_condition_2 as disease_name
        from raw_sheet
      union all
      select clinical_trial_title,
             clinical_trial_condition_3 as disease_name
        from raw_sheet
   )
    where clinical_trial_title is not null
      and disease_name is not null;

commit;