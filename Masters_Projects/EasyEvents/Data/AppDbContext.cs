/**** This class is derived from dbcontext  and contains table structure for the database   ****
 **** contains methods to create table strucutre                                            ****
 **** Author - Tejashri Joshi                                                               ****
 **** Date   - 12/9/2020                                                                    ****/
using EasyEvents.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Builders;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace EasyEvents.Data
{
    public class AppDbContext : DbContext
    {
        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {

        }
        public DbSet<Users> Users { get; set; }
        public DbSet<Events> Events { get; set; }
        public DbSet<UserEvents> UserEvents { get; set; }
        public DbSet<EventType> EventTypes { get; set; }
        public DbSet<Venues> Venues { get; set; }
        protected override void OnModelCreating(ModelBuilder builder)
        {
            //base.OnModelCreating(builder);
            foreach (var relationship in builder.Model.GetEntityTypes().SelectMany(e => e.GetForeignKeys()))
            {
                relationship.DeleteBehavior = DeleteBehavior.Restrict;
            }

            base.OnModelCreating(builder);
            builder.Entity<EventType>(ConfigureEventType);
            builder.Entity<Venues>(ConfigureVenue);
            builder.Entity<Users>(ConfigureUser);
            builder.Entity<Events>(ConfigureEvent);
            builder.Entity<UserEvents>(ConfigureUserEvent);
        }

        private void ConfigureUserEvent(EntityTypeBuilder<UserEvents> builder)
        {
            builder.ToTable("UserEvents");
            builder.Property(ue => ue.UserEventId).UseHiLo("userevents_id_hilo").IsRequired().ValueGeneratedOnAdd().UseIdentityColumn();
            builder.HasOne(ue => ue.Events).WithMany().HasForeignKey(ue => ue.EventId);
            builder.HasOne(ue => ue.Users).WithMany().HasForeignKey(ue => ue.GuestId);
            builder.Property(ue => ue.RFIDTagId).IsRequired();
            builder.Property(ue => ue.IsAttended).IsRequired(false);
        }

        private void ConfigureUser(EntityTypeBuilder<Users> builder)
        {
            builder.ToTable("Users");
            builder.Property(u => u.UserId).UseHiLo("user_id_hilo").IsRequired().ValueGeneratedOnAdd().UseIdentityColumn();
            builder.Property(u => u.UserName).IsRequired();
            builder.Property(u => u.FirstName).IsRequired();
            builder.Property(u => u.LastName).IsRequired();
            builder.Property(u => u.Password).IsRequired();
            builder.Property(u => u.EmailAddress).IsRequired();
            builder.Property(u => u.Age).IsRequired();
            builder.Property(u => u.Gender).IsRequired();
            builder.Property(u => u.Role).IsRequired();

        }
        private void ConfigureEvent(EntityTypeBuilder<Events> builder)
        {
            builder.ToTable("Events");
            builder.Property(e => e.EventId).UseHiLo("event_id_hilo").IsRequired().ValueGeneratedOnAdd().UseIdentityColumn();
            builder.Property(e => e.EventName).IsRequired();
            builder.Property(e => e.Description).IsRequired();
            builder.Property(e => e.DateTime).IsRequired();
            builder.Property(e => e.Time).IsRequired();
            builder.HasOne(e => e.EventType).WithMany().HasForeignKey(e => e.EventTypeId);
            builder.HasOne(e => e.Venue).WithMany().HasForeignKey(e => e.VenueId);
            builder.HasOne(e => e.User).WithMany().HasForeignKey(e => e.HostId);
        }

        private void ConfigureVenue(EntityTypeBuilder<Venues> builder)
        {
            builder.ToTable("Venues");
            builder.Property(v => v.VenueId).UseHiLo("venue_id_hilo").IsRequired().ValueGeneratedOnAdd().UseIdentityColumn();
            builder.Property(v => v.VenueName).IsRequired();
            builder.Property(v => v.Address).IsRequired();
            builder.Property(v => v.City).IsRequired();
            builder.Property(v => v.State).IsRequired();
            builder.Property(v => v.ZipCode).IsRequired();
        }
        private void ConfigureEventType(EntityTypeBuilder<EventType> builder)
        {
            builder.ToTable("EventType");
            builder.Property(et => et.EventTypeId).UseHiLo("eventtype_id_hilo").IsRequired().ValueGeneratedOnAdd().UseIdentityColumn();
            builder.Property(et => et.EventTypeName).IsRequired();
        }
    }
}
